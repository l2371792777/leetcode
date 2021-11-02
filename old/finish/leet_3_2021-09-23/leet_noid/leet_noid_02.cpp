#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class MinStack
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right);
    int test();
};

ListNode *MinStack::reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || right - left < 1)
    {
        return head;
    }
    ListNode *llhead;
    ListNode *lhead;
    lhead = head;
    int i;
    for (i = 1; i < left; i++)
    {
        llhead = lhead;
        lhead = lhead->next;
    }
    ListNode *mhead = lhead->next;
    ListNode *rhead = mhead->next;
    for (i; i < right; i++)
    {
        mhead->next = lhead;
        lhead = mhead;
        mhead = rhead;
        if (rhead != NULL)
            rhead = rhead->next;
    }
    if (left == 1)
    {
        head->next = mhead;
        head = lhead;
    }
    else
    {
        llhead->next->next = mhead;
        llhead->next = lhead;
    }
    return head;
}

int MinStack::test()
{
    ListNode hogo(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, NULL)))));
    MinStack init;
    ListNode *ptr = &hogo;
    ListNode *cptr = ptr;
    while (cptr != NULL)
    {
        cout << cptr->val;
        cptr = cptr->next;
    }
    ptr = init.reverseBetween(ptr, 2, 5);
    cptr = ptr;
    cout << endl;
    while (cptr != NULL)
    {
        cout << cptr->val;
        cptr = cptr->next;
    }
    return 0;
}