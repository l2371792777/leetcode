//...leetcode_437_2021-09-28
//...https://leetcode-cn.com/problems/path-sum-iii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Definition for a binary tree node.
struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode() : val(0), left(nullptr), right(nullptr) {}
    ListNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ListNode(int x, ListNode *left, ListNode *right) : val(x), left(left), right(right) {}
};

int pathSum(ListNode *root, int targetSum);
int rootSum(ListNode *root, int targetSum);

void test();

int main()
{
    test();
    return 0;
}

void test()
{
}

int rootSum(ListNode *root, int targetSum)
{
    if (!root)
    {
        return 0;
    }

    int ret = 0;
    if (root->val == targetSum)
    {
        ret++;
    }

    ret += rootSum(root->left, targetSum - root->val);
    ret += rootSum(root->right, targetSum - root->val);
    return ret;
}

int pathSum(ListNode *root, int targetSum)
{
    if (!root)
    {
        return 0;
    }

    int ret = rootSum(root, targetSum);
    ret += pathSum(root->left, targetSum);
    ret += pathSum(root->right, targetSum);
    return ret;
}