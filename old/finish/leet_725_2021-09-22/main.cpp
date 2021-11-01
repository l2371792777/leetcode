#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void test();
vector<ListNode *> splitListToParts(ListNode *head, int k);

int main()
{
    test();
    return 0;
}

void test()
{
    ListNode hogo(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, NULL)))));
    splitListToParts(&hogo, 2);
}

vector<ListNode *> splitListToParts(ListNode *head, int k)
{
    vector<ListNode *> parts(k, nullptr);

    //获取链表长度
    int n = 0;
    ListNode *hogo = head;
    while (hogo != NULL)
    {
        n++;
        hogo = hogo->next;
    }

    int quotient = n / k, remainder = n % k;
    int partsize = 0;
    hogo = head;
    for (int i = 0; i < k && hogo != NULL; i++)
    {
        parts[i] = hogo;
        if (i < remainder)
        {
            partsize = quotient + 1;
        }
        else
        {
            partsize = quotient;
        }
        for (int j = 1; j < partsize; j++)
        {
            cout <<partsize<<" "<< hogo->val << endl;
            hogo = hogo->next;
        }
        ListNode *temp = hogo->next;
        hogo->next = NULL;
        hogo = temp;
    }
    return parts;
}