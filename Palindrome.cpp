#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> l;
    int val;

   
    while (cin >> val && val != -1) {
        l.push_back(val);
    }

    auto frontIt = l.begin();
    auto backIt = prev(l.end()); 
    
    bool isPalindrome = true;

    while (frontIt != backIt && next(frontIt) != backIt) {
        if (*frontIt != *backIt) {
            isPalindrome = false;
            break;
        }
        ++frontIt;   
        --backIt;    
    }

    if (isPalindrome) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
