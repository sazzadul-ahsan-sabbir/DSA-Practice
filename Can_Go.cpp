#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> grid;
vector<vector<bool>> visited;
int sx, sy, ex, ey;  

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool dfs(int x, int y) {
    if (x == ex && y == ey) return true; 

    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny) && !visited[nx][ny] &&
            (grid[nx][ny] == '.' || grid[nx][ny] == 'B')) {
            if (dfs(nx, ny)) return true;
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 'B') {
                ex = i;
                ey = j;
            }
        }
    }

    if (dfs(sx, sy)) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
