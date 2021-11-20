/**
 * @description leetcode练习
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
#include <cmath>

using namespace std;

/**
 * 二叉树
 */
struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    /**
     * 测试
     * @param
     */
    void test()
    {
        vector<int> test = {
            1,1,1,1};
        cout << findLHS(test);
    }

    /**
     * 题解
     * @param
     */
    int findLHS(vector<int> &nums)
    {
        map<int, int> res;
        for (int i : nums)
        {
            res[i]++;
        }
        int fmax = 0;
        int tmp = 0;
        for (int i : nums)
        {
            if (res[i + 1] == 0)
            {
                continue;
            }
            tmp =res[i] + res[i + 1];
            if (tmp > fmax)
            {
                fmax = tmp;
            }
        }
        return fmax;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
