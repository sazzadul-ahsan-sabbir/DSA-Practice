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

// Function to build tree from level order input
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

// Collect leaf nodes
void getLeafNodes(Node* root, vector<int>& leaves) {
    if (!root) return;
    if (!root->left && !root->right) {
        leaves.push_back(root->data);
        return;
    }
    getLeafNodes(root->left, leaves);
    getLeafNodes(root->right, leaves);
}

int main() {
    vector<int> arr;
    int x;
    while (cin >> x) {
        arr.push_back(x);
    }

    Node* root = buildTree(arr);

    vector<int> leaves;
    getLeafNodes(root, leaves);

    // Sort in descending order
    sort(leaves.rbegin(), leaves.rend());

    for (int val : leaves) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
