#include <iostream>

using namespace std;

struct RandomListNode
{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	RandomListNode() {}
};

RandomListNode* newList()
{
	RandomListNode* L = new RandomListNode;
	L->next = NULL;
	L->random = NULL;
	RandomListNode* q = L;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		RandomListNode *p = new RandomListNode;
		cin >> p->label;
		q->next = p;
		q->random = p;
		q = p;
	}
	q->next = NULL;
	q->random = NULL;
	return L;
}

RandomListNode* Clone(RandomListNode* pHead)
{
	if (!pHead) return NULL;
	RandomListNode* currNode = pHead;
	while (currNode)
	{
		RandomListNode* node = new RandomListNode(currNode->label);
		node->next = currNode->next;
		currNode->next = node;
		currNode = node->next;
	}
	currNode = pHead;
	while (currNode)
	{
		RandomListNode* node = currNode->next;
		if (currNode->random)
			node->random = currNode->random->next;
		currNode = node->next;
	}
	RandomListNode* pCloneHead = pHead->next;
	RandomListNode* tmp;
	currNode = pHead;
	while (currNode->next)
	{
		tmp = currNode->next;
		currNode->next = tmp->next;
		currNode = tmp;
	}
	return pCloneHead;
}

int main()
{
	ios::sync_with_stdio(false);
	RandomListNode* L1 = newList();
	RandomListNode* L2 = Clone(L1);
	RandomListNode* p = L2->next;
	while (p)
	{
		cout << p->label << " ";
		p = p->next;
	}
	cout << endl;
	return 0;
}