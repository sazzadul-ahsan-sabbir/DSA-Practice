#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Build tree from level order
Node* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return NULL;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        Node* curr = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Find depth (max level)
int findDepth(Node* root) {
    int d = 0;
    while (root) {
        d++;
        root = root->left;
    }
    return d;
}

// Check if perfect binary tree
bool isPerfect(Node* root, int depth, int level = 1) {
    if (!root) return true;

    // Leaf node
    if (!root->left && !root->right) {
        return (depth == level);
    }

    // Internal node must have 2 children
    if (!root->left || !root->right) return false;

    return isPerfect(root->left, depth, level + 1) &&
           isPerfect(root->right, depth, level + 1);
}

int main() {
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }

    Node* root = buildTree(arr);

    int depth = findDepth(root); // total depth
    if (isPerfect(root, depth)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
