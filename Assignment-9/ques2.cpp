#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>
using namespace std;
void dfs(int node,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adjList,vector<int> &component){
    component.push_back(node);
    visited[node]=true;
    for(auto i:adjList[node]){
        if(!visited[i]){
            dfs(i,visited,adjList,component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V,int E,vector<vector<int>> edges){
    //prepareAdjList
    unordered_map<int,list<int>> adjList;
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<vector<int>> ans;
    unordered_map<int,bool> visited;
    //traverse all components of a graph
    for(int i=0;i<V;i++){
        if(!visited[i]){
            vector<int> component;
            dfs(i,visited,adjList,component);
            ans.push_back(component);
        }
    }
    return ans;
}
int main(){
    int vertex=6;
    int totaledges=5;
    vector<vector<int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({1,3});
    edges.push_back({2,4});
    edges.push_back({3,5});
    vector<vector<int>> result=depthFirstSearch(vertex,totaledges,edges);
    cout<<"DFS traversal:";
    for(auto i:result){
        for(int j:i){
        cout<<j<<" ";
        }
    }
    cout<<endl;
    return 0;
}