#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);  
    }

    int q;
    cin >> q;

    while (q--) {
        int u, v;
        cin >> u >> v;

      if (u == v)
    cout << "YES\n";
else if (adj[u].count(v))
    cout << "YES\n";
else
    cout << "NO\n";

    }

    return 0;
}
