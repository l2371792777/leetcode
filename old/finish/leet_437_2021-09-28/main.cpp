//...leetcode_437_2021-09-28
//...https://leetcode-cn.com/problems/path-sum-iii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int pathSum(TreeNode *root, int targetSum);
int rootSum(TreeNode *root, int targetSum);

void test();

int main()
{
    test();
    return 0;
}

void test()
{
}

int rootSum(TreeNode *root, int targetSum)
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

int pathSum(TreeNode *root, int targetSum)
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