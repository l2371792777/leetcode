#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
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
    int getMoneyAmount(int n)
    {
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int i = n - 1; i >= 1; i--)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int minCost = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    int cost = k + max(f[i][k - 1], f[k + 1][j]);
                    minCost = min(minCost, cost);
                }
                f[i][j] = minCost;
            }
        }
        return f[1][n];
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
