#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
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
        Node* curr = q.front(); q.pop();

        int leftVal, rightVal;
        if (!(cin >> leftVal)) break;
        if (!(cin >> rightVal)) break;

        if (leftVal != -1) {
            curr->left = new Node(leftVal);
            q.push(curr->left);
        }
        if (rightVal != -1) {
            curr->right = new Node(rightVal);
            q.push(curr->right);
        }
    }
    return root;
}

bool isLeaf(Node* node) {
    return (node && !node->left && !node->right);
}

void addLeftBoundary(Node* root, vector<int>& res) {
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr))
            res.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}

void addRightBoundary(Node* root, vector<int>& res) {
    Node* curr = root->right;
    vector<int> temp;
    while (curr) {
        if (!isLeaf(curr))
            temp.push_back(curr->val);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int i = (int)temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

void addLeaves(Node* root, vector<int>& res) {
    if (!root) return;
    if (isLeaf(root)) {
        res.push_back(root->val);
        return;
    }
    addLeaves(root->left, res);
    addLeaves(root->right, res);
}

int main() {
    Node* root = buildTree();
    if (!root) return 0;

    vector<int> result;

    // For this problem, output order is leaves (leftmost to rightmost), then left boundary upwards to root, then right boundary downwards
    // So print leaves first from left to right leaf nodes
    addLeaves(root, result);

    // Then add left boundary from bottom to top (excluding leaves and root already in leaves)
    vector<int> leftBoundary;
    Node* curr = root->left;
    while (curr) {
        if (!isLeaf(curr)) leftBoundary.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
    for (int i = (int)leftBoundary.size() - 1; i >= 0; --i) {
        result.insert(result.begin(), leftBoundary[i]);
    }

    // Add root node in the middle if not leaf (already in leaves)
    if (!isLeaf(root)) {
        result.insert(result.begin() + leftBoundary.size(), root->val);
    }

    // Add right boundary bottom to top
    vector<int> rightBoundary;
    curr = root->right;
    while (curr) {
        if (!isLeaf(curr)) rightBoundary.push_back(curr->val);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for (int val : rightBoundary) {
        result.push_back(val);
    }

    // Output result
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}
