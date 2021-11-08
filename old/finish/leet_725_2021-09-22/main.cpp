#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

//   Definition for singly-linked list.
struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode() : val(0), next(nullptr) {}
    TreeNode(int x) : val(x), next(nullptr) {}
    TreeNode(int x, TreeNode *next) : val(x), next(next) {}
};

void test();
vector<TreeNode *> splitListToParts(TreeNode *head, int k);

int main()
{
    test();
    return 0;
}

void test()
{
    TreeNode hogo(1, new TreeNode(2, new TreeNode(3, new TreeNode(4, new TreeNode(5, NULL)))));
    splitListToParts(&hogo, 2);
}

vector<TreeNode *> splitListToParts(TreeNode *head, int k)
{
    vector<TreeNode *> parts(k, nullptr);

    //获取链表长度
    int n = 0;
    TreeNode *hogo = head;
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
        TreeNode *temp = hogo->next;
        hogo->next = NULL;
        hogo = temp;
    }
    return parts;
}