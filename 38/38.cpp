#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode() {}
};

TreeNode* newTree()
{
	TreeNode* node = new TreeNode;
	int x;
	cin >> x;
	if (!x)node = NULL;
	else
	{
		node->val = x;
		node->left = newTree();
		node->right = newTree();
	}
	return node;
}

int TreeDepth(TreeNode* root)
{
	if (!root)return 0;
	return max(TreeDepth(root->left) + 1, TreeDepth(root->right) + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	TreeNode* root = NULL;
	root = newTree();
	cout << TreeDepth(root);
	return 0;
}