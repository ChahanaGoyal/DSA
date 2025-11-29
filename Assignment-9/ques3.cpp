// Kruskal
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <limits.h>
using namespace std;
bool cmp(vector<int> &a, vector<int> &b)
{ // comparator
    return a[2] < b[2];
}
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
    if (rank[u] < rank[v])
    {
        parent[u] = v;
        rank[v]++;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
        rank[u]++;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}
// Prim
vector<pair<pair<int, int>, int>> prim(int n, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);
    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }
    key[1] = 0; // source node
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        // find min node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        // mark min node as true
        mst[u] = true;
        // check adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    { // starting from 2 as parent of source node,1 here, is -1
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
int main(){
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;
    vector<vector<int>> edgesK;               // for Kruskal => {u, v, w}
    vector<pair<pair<int, int>, int>> edgesP; // for Prim => {{u, v}, w}
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edgesK.push_back({u - 1, v - 1, w}); // 0-based indexing for Kruskal
        edgesP.push_back({{u, v}, w});       // 1-based indexing for Prim
    }
    //Kruskal output
    int kruskalMST = minimumSpanningTree(edgesK, n);
    cout << endl << "Kruskal MST Cost: " << kruskalMST << endl;
    //Prim output
    vector<pair<pair<int, int>, int>> primResult = prim(n, edgesP);
    cout << endl << "Prim MST Result (edges): " << endl;
    int primCost = 0;
    for (auto &it : primResult)
    {
        cout << it.first.first << " - " << it.first.second << "  weight: " << it.second << endl;
        primCost += it.second;
    }
    cout << endl<< "Prim MST Cost: " << primCost << endl;
    return 0;
}