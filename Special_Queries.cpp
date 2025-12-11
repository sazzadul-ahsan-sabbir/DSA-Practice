#include <bits/stdc++.h>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    queue<string> l; 

    while(Q--) {
        int c;
        cin >> c;

        if(c == 0) {
            string name;
            cin >> name;
            l.push(name); 
        } 
        else if(c == 1) {
            if(l.empty()) {
                cout << "Invalid" << endl; 
            } else {
                cout << l.front() << endl; 
                l.pop(); 
            }
        }
    }

    return 0;
}
