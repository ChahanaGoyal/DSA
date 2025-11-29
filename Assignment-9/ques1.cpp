#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;
void prepareAdjList(unordered_map<int,set<int>> &adjList,vector<pair<int,int>> &edges){
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}
void bfs(unordered_map<int,set<int>> &adjList,unordered_map<int,bool> &visited,vector<int> &ans,int node){
    queue<int> q;
    q.push(node);
    visited[node]=1;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        //store frontNode into ans
        ans.push_back(frontNode);
        //traverse all neighbours of frontNode
        for(auto i:adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
vector<int> BFS(int vertex,vector<pair<int,int>> edges){
    unordered_map<int,set<int>> adjList;
    vector<int> ans;
    unordered_map<int,bool> visited;
    prepareAdjList(adjList,edges);
    //traverse all components of a graph
    for(int i=0;i<vertex;i++){
        if(!visited[i]){
            bfs(adjList,visited,ans,i);
        }
    }
    return ans;
}
int main(){
    int vertex=6;
    vector<pair<int,int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,2});
    edges.push_back({1,3});
    edges.push_back({2,4});
    edges.push_back({3,5});
    vector<int> result=BFS(vertex,edges);
    cout<<"BFS traversal:";
    for(int x:result){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}