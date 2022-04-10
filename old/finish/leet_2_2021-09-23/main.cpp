#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
void test();

int main()
{
    test();
    return 0;
}

void test()
{
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int temp = 0, carry = 0;
    ListNode *n1 = l1, *n2 = l2, *head = l1;
    while (l1 != NULL && l2 != NULL)
    {
        temp = carry + l1->val + l2->val;
        if (temp > 9)
        {
            l1->val = temp - 10;
            carry = 1;
        }
        else
        {
            carry = 0;
            l1->val = temp;
        }
        n1 = l1, n2 = l2;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 == NULL)
    {
        n1->next = l2;
    }
    n1->next->val += carry;

    return head;
}