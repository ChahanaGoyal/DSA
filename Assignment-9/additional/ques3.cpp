#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;
int networkDelayTime(int N, const vector<vector<int>>& times, int K) {
    const int INF = INT_MAX / 2;
    vector<vector<pair<int,int>>> adj(N + 1);
    for (auto &t : times) {
        int u = t[0], v = t[1], w = t[2];
        adj[u].push_back({v, w});
    }
    vector<int> dist(N + 1, INF);
    dist[K] = 0;
    using P = pair<int,int>; // cost, node
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, K);
    while (!pq.empty()) {
        auto temp = pq.top();
        int curDist = temp.first;
        int u = temp.second;
        pq.pop();
        if (curDist > dist[u]) continue;
        for (auto &pr : adj[u]) {
            int v = pr.first, w = pr.second;
            if (curDist + w < dist[v]) {
                dist[v] = curDist + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] == INF) return -1;
        answer = max(answer, dist[i]);
    }
    return answer;
}
int main() {
    int N, E, K;
    cin >> N >> E >> K;
    vector<vector<int>> times(E, vector<int>(3));
    for (int i = 0; i < E; i++) {
        cin >> times[i][0] >> times[i][1] >> times[i][2];
    }
    int answer = networkDelayTime(N, times, K);
    cout << answer << endl;
    return 0;
}