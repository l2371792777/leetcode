//...leetcode_430_2021-09-24
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

void test();

int main()
{
    test();
    return 0;
}

void test()
{
}

Node *flatten(Node *head)
{
    //递归
    Node *temp = head, *temp_next = head, *get_child = head;
    while (temp != NULL)
    {
        if (temp->child != NULL)
        {
            get_child = flatten(temp->child);
            temp->child = NULL;
            get_child->prev = temp;
            if (temp->next != NULL)
            {
                temp_next = temp->next;
                temp->next = get_child;
                while (get_child->next != NULL)
                {
                    get_child = get_child->next;
                }
                get_child->next = temp_next;
                temp_next->prev = get_child;
                temp = get_child;
            }
            else
            {
                temp->next = get_child;
            }
        }
        temp = temp->next;
    }
    return head;
}