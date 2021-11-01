//...leetcode_230_2021-10-17
//...https://leetcode-cn.com/problems/submissions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void test();
int kthSmallest(TreeNode *root, int k);

int main()
{
    test();
    return 0;
}

void test()
{
}
int account = 0;
int ans = -1;
int kthSmallest(TreeNode *root, int k)
{
    dfs(root, k);
    return ans;
}

void dfs(TreeNode *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    dfs(root->left, k);
    account++;
    if (account == k)
    {
        ans = root->val;
    }
    dfs(root->right, k);
}