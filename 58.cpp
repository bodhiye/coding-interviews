#include <iostream>

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

bool symmetrical(TreeNode *left, TreeNode *right) {
    if (!left && !right)
        return true;
    if (left && right)
        return left->val == right->val && symmetrical(left->left, right->right) &&
               symmetrical(left->right, right->left);
    return false;
}

bool isSymmetrical(TreeNode *pRoot) {
    if (!pRoot)
        return true;
    return symmetrical(pRoot->left, pRoot->right);
}

int main() {
    ios::sync_with_stdio(false);
    TreeNode *root = NULL;
    root = newTree();
    cout << isSymmetrical(root);
    return 0;
}
