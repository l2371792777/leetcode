#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void test()
    {
    }
    bool dfs(TreeNode *Left, TreeNode *Right)
    {
        if (Right == NULL && Left == NULL)
        {
            return true;
        }
        if (Right == NULL || Left == NULL || Right->val != Left->val)
        {
            return false;
        }
        return dfs(Left->left, Right->right) && dfs(Left->right, Right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        return dfs(root->left, root->right);
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
