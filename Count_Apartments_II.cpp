#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int dfs(int x, int y) {
    visited[x][y] = true;
    int room_count = 1;  

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (valid(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '.') {
            room_count += dfs(nx, ny);
        }
    }
    return room_count;
}

int main() {
    cin >> n >> m;
    grid.resize(n);
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<int> a;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int rooms = dfs(i, j);
                a.push_back(rooms);
            }
        }
    }

    if (a.empty()) {
        cout << -1 << "\n";
        return 0;
    }

    sort(a.begin(), a.end());

    for (int x : a) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
