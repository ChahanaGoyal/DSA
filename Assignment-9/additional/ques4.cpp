#include <iostream>
#include <vector>
using namespace std;
void dfsIsland(int r, int c, const vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    int m = grid.size();
    int n = grid[0].size();
    visited[r][c] = true;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, 1, -1};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
            if (!visited[nr][nc] && grid[nr][nc] == '1') {
                dfsIsland(nr, nc, grid, visited);
            }
        }
    }
}
int numIslands(const vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                count++;
                dfsIsland(i, j, grid, visited);
            }
        }
    }
    return count;
}
int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    int answer = numIslands(grid);
    cout << answer << "\n";
    return 0;
}