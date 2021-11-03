#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <string>
#include <cmath>

using namespace std;

//   Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
        {
            return head;
        }
        vector<Node *> hogo;
        vector<Node *> Nhogo;

        Node *root = head;
        while (root != NULL)
        {
            hogo.push_back(root);
            root = root->next;
        }
        root = head;
        int num = 0;
        while (root != NULL)
        {
            Nhogo.push_back(new Node(root->val));
            if (num != 0)
            {
                Nhogo[num - 1]->next = Nhogo[num];
            }
            root = root->next;
            num++;
        }

        root = Nhogo[0];
        while (head != NULL)
        {
            if (head->random != NULL)
            {
                auto it = find(hogo.begin(), hogo.end(), head->random);
                num = it - hogo.begin();
                root->random = Nhogo[num];
            }
            head = head->next;
            root = root->next;
        }
        root = Nhogo[0];
        return root;
    }
};
int main()
{
    Solution solu;
    // solu.test();
    return 0;
}
