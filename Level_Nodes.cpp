#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int val;
    cin >> val;
    if (val == -1) return nullptr;

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftVal, rightVal;
        if (!(cin >> leftVal)) break;
        if (!(cin >> rightVal)) break;

        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }

    return root;
}

void printLevelNodes(Node* root, int level) {
    if (!root) {
        cout << "Invalid" << endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    int currentLevel = 0;
    bool levelFound = false;

    while (!q.empty()) {
        int size = q.size();
        if (currentLevel == level) {
            levelFound = true;
            for (int i = 0; i < size; i++) {
                Node* node = q.front(); q.pop();
                cout << node->val;
                if (i < size - 1) cout << " ";
            }
            cout << endl;
            break;
        }

        for (int i = 0; i < size; i++) {
            Node* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        currentLevel++;
    }

    if (!levelFound) {
        cout << "Invalid" << endl;
    }
}

int main() {
    Node* root = buildTree();
    int level;
    cin >> level;

    printLevelNodes(root, level);

    return 0;
}
