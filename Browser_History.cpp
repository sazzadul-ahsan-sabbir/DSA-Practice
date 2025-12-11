#include <bits/stdc++.h>
using namespace std;

int main() {
    list<string> webList;
    string address;
    while (cin >> address && address != "end") {
        webList.push_back(address);
    }
    int q;
    cin >> q;
    cin.ignore(); 

    auto current = webList.begin(); 
    for (int i = 0; i < q; i++) {
        string command;
        getline(cin, command); 

        if (command.substr(0, 5) == "visit") {
            string site = command.substr(6);
            auto it = find(webList.begin(), webList.end(), site);

            if (it != webList.end()) {
                current = it;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next") {
            auto temp = current;
            ++temp;
            if (temp != webList.end()) {
                current = temp;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev") {
            if (current != webList.begin()) {
                --current;
                cout << *current << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
