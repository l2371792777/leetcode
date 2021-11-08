#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode() : val(0), next(nullptr) {}
    TreeNode(int x) : val(x), next(nullptr) {}
    TreeNode(int x, TreeNode *next) : val(x), next(next) {}
};
class MinStack
{
public:
    TreeNode *reverseBetween(TreeNode *head, int left, int right);
    int test();
};

TreeNode *MinStack::reverseBetween(TreeNode *head, int left, int right)
{
    if (head == NULL || right - left < 1)
    {
        return head;
    }
    TreeNode *llhead;
    TreeNode *lhead;
    lhead = head;
    int i;
    for (i = 1; i < left; i++)
    {
        llhead = lhead;
        lhead = lhead->next;
    }
    TreeNode *mhead = lhead->next;
    TreeNode *rhead = mhead->next;
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
    TreeNode hogo(1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5, NULL)))));
    MinStack init;
    TreeNode *ptr = &hogo;
    TreeNode *cptr = ptr;
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