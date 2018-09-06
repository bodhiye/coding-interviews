#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    ListNode() {}
};

ListNode *newList() {
    ListNode *L = new ListNode;
    L->next = NULL;
    ListNode *q = L;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ListNode *p = new ListNode;
        cin >> p->val;
        q->next = p;
        q = p;
    }
    q->next = NULL;
    return L->next;
}

ListNode *EntryNodeOfLoop(ListNode *pHead) {
    if (pHead == NULL || pHead->next == NULL)
        return NULL;
    ListNode *p1 = pHead, *p2 = pHead;
    while (p2 != NULL && p2->next != NULL) {
        p1 = p1->next;
        p2 = p2->next->next;
        if (p1 == p2) {
            p2 = pHead;
            while (p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            if (p1 == p2)
                return p1;
        }
    }
    return NULL;
}

int main() {
    ios::sync_with_stdio(false);
    ListNode *L = newList();
    cout << EntryNodeOfLoop(L)->val;
    return 0;
}
