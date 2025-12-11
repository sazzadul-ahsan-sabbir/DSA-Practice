#include <bits/stdc++.h>
using namespace std;

int main() {
    list<int> myList;
    int val;

    while (cin >> val && val != -1) {
        myList.push_back(val);
    }

    myList.sort();

    myList.unique();

    for (int v : myList) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}
