#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> comp_nodes;

void dfs(int u) {
    visited[u] = true;
    comp_nodes.push_back(u);
    for (int v : graph[u]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.assign(n, vector<int>());
    visited.assign(n, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> comp(n); 

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            comp_nodes.clear();
            dfs(i);

            sort(comp_nodes.rbegin(), comp_nodes.rend());

            for (int node : comp_nodes) {
                comp[node] = comp_nodes;
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int x;
        cin >> x;

        vector<int> ans;
        for (int node : comp[x]) {
            if (node != x)
                ans.push_back(node);
        }

        if (ans.empty())
            cout << -1 << "\n";
        else {
            for (int v : ans)
                cout << v << " ";
            cout << "\n";
        }
    }

    return 0;
}
