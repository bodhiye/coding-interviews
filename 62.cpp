#include <iostream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }

    TreeNode() {}
};

TreeNode *newTree() {
    TreeNode *node = new TreeNode;
    int x;
    cin >> x;
    if (!x)node = NULL;
    else {
        node->val = x;
        node->left = newTree();
        node->right = newTree();
    }
    return node;
}

int count = 0;

TreeNode *KthNode(TreeNode *pRoot, int k) {
    if (pRoot) {
        TreeNode *node = KthNode(pRoot->left, k);
        if (node) return node;
        if (++count == k)return pRoot;
        node = KthNode(pRoot->right, k);
        if (node)return node;
    }
    return NULL;
}

int main() {
    ios::sync_with_stdio(false);
    int k;
    cin >> k;
    TreeNode *root = NULL;
    root = newTree();
    cout << KthNode(root, k)->val;
    return 0;
}
