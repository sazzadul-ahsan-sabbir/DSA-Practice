#include <bits/stdc++.h>
using namespace std;

int main() {
    list<long long> dll;  
    int q; 
    if (!(cin >> q)) return 0;

    while (q--) {
        int x; long long v;
        cin >> x >> v;

        if (x == 0) {
            dll.push_front(v);
        } else if (x == 1) {
            dll.push_back(v);
        } else if (x == 2) {
            if (v >= 0 && v < (long long)dll.size()) {
                auto it = dll.begin();
                advance(it, (long long)v);
                dll.erase(it);
            }
        }
        cout << "L -> ";
        for (auto v : dll) cout << v << ' ';
        cout << '\n';
        cout << "R -> ";
        for (auto it = dll.rbegin(); it != dll.rend(); ++it) cout << *it << ' ';
        cout << '\n';
    }
    return 0;
}
