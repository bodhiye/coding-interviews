#include <iostream>

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

void preOrder(TreeNode *pRoot)
{
	if (pRoot)
	{
		cout << pRoot->val << " ";
		preOrder(pRoot->left);
		preOrder(pRoot->right);
	}
}

void Mirror(TreeNode *pRoot)
{
	if (pRoot == NULL)
		return;
	TreeNode *temp = pRoot->left;
	pRoot->left = pRoot->right;
	pRoot->right = temp;
	Mirror(pRoot->left);
	Mirror(pRoot->right);
}

int main()
{
	ios::sync_with_stdio(false);
	TreeNode* pRoot = NULL;
	pRoot = newTree();
	Mirror(pRoot);
	preOrder(pRoot);
	return 0;
}