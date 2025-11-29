#include <iostream>
#include <set>
#include <unordered_map>
#include <list>
#include <vector>
#include <limits.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dist(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dist[i] = INT_MAX;
    }
    set<pair<int, int>> st;
    dist[source] = 0;
    st.insert(make_pair(0, source));
    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;
        // remove top record now
        st.erase(st.begin());
        // traverse on neighbours
        for (auto neighbour : adj[topNode])
        {
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                // if record found,then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }
                // update distance
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // push record in set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    return dist;
}
int main()
{
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    vector<vector<int>> vec(edges, vector<int>(3)); // no. of rows are equal to no. of edges and each row is a vector of 3 integers
    cout << "Enter edges in format: u v w" << endl;
    for (int i = 0; i < edges; i++)
    {
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2];
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    vector<int> shortest = dijkstra(vec, vertices, edges, source);
    cout << "\nShortest distances from source " << source << ":" << endl;
    for (int i = 0; i < vertices; i++)
    {
        cout << "Node " << i << " : ";
        if (shortest[i] == INT_MAX)
            cout << "INF" << endl;
        else
            cout << shortest[i] << endl;
    }
    return 0;
}