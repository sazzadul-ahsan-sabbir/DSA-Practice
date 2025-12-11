#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

// directions using vector<pair<int,int>>
vector<pair<int,int>> dir = {
    {-1, 0},  // up
    {1, 0},   // down
    {0, -1},  // left
    {0, 1}    // right
};

void dfs(int x, int y) {
    visited[x][y] = true;

    for (auto d : dir) {
        int nx = x + d.first;
        int ny = y + d.second;

        // boundary check
        if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
            // DFS only on floor '.'
            if (grid[nx][ny] == '.' && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) 
        cin >> grid[i];

    int rooms = 0;

    // Scan the whole grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Start DFS only on floor (.)
            if (grid[i][j] == '.' && !visited[i][j]) {
                rooms++;
                dfs(i, j);
            }
        }
    }

    cout << rooms << endl;
    return 0;
}
