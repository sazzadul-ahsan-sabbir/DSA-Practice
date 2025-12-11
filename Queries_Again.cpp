#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> dll; 
    int q;
    cin >> q;

    while (q--) {
        int x, v;
        cin >> x >> v;

        if (x < 0 || x > (int)dll.size()) {
            cout << "Invalid" << endl;
            continue;
        }

     
        auto it = dll.begin();
        advance(it, x);

     
        dll.insert(it, v);

      
        cout << "L -> ";
        for (int val : dll) {
            cout << val << " ";
        }
        cout << endl;

      
        cout << "R -> ";
        for (auto rit = dll.rbegin(); rit != dll.rend(); ++rit) {
            cout << *rit << " ";
        }
        cout << endl;
    }

    return 0;
}
