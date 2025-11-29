#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
class Node {
    public:
    int cost;
    int r;
    int c;
    Node(int _cost, int _r, int _c) : cost(_cost), r(_r), c(_c) {}
};
// For priority queue: we want lowest cost first
class Compare {
    public:
    bool operator()(const Node &a, const Node &b) {
        return a.cost > b.cost;
    }
};
int minCostGrid(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    const int INF = INT_MAX / 2;
    vector<vector<int>> dist(m, vector<int>(n, INF));
    priority_queue<Node, vector<Node>, Compare> pq;
    dist[0][0] = grid[0][0];
    pq.emplace(grid[0][0], 0, 0);
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();
        if (current.cost > dist[current.r][current.c]) {
            continue;
        }
        // If reached destination, we can optionally break
        if (current.r == m - 1 && current.c == n - 1) {
            return current.cost;
        }
        for (int i = 0; i < 4; i++) {
            int nr = current.r + dr[i];
            int nc = current.c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                int nextCost = current.cost + grid[nr][nc];
                if (nextCost < dist[nr][nc]) {
                    dist[nr][nc] = nextCost;
                    pq.emplace(nextCost, nr, nc);
                }
            }
        }
    }
    return dist[m-1][n-1];
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int answer = minCostGrid(grid);
    cout << answer << "\n";
    return 0;
}