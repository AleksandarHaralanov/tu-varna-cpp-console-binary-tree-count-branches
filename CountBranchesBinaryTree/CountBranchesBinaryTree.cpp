#include <iostream>

using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
};

int branchCount = 0;

static TreeNode* createNode(int key) {
    TreeNode* node = new TreeNode();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

static TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    }
    else if (value <= root->key) {
        root->left = insertNode(root->left, value);
    }
    else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

static void countBranches(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    if (root->left && root->right) {
        branchCount++;
    }

    countBranches(root->left);
    countBranches(root->right);
}

int main() {
    TreeNode* root = nullptr;
    int nodeCount, nodeKey;

    cout << "How many nodes to add to the tree: ";
    cin >> nodeCount;

    for (int i = 0; i < nodeCount; i++) {
        cout << "Key for node " << i + 1 << ": ";
        cin >> nodeKey;
        root = insertNode(root, nodeKey);
    }

    countBranches(root);
    cout << branchCount;

    return 0;
}
