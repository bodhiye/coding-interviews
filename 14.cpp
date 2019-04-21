#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
	ListNode() {}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	ListNode *p, *q;
	p = q = pListHead;
	int i = 0;
	for (; p != NULL; i++)
	{
		if (i >= k)
			q = q->next;
		p = p->next;
	}
	return i < k ? NULL : q;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	ListNode* L = new ListNode;
	L->next = NULL;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		ListNode *p = new ListNode;
		cin >> p->val;
		p->next = L->next;
		L->next = p;
	}
	cin >> k;
	cout << FindKthToTail(L, k)->val << endl;
	return 0;
}