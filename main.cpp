/**
 * @description leetcode练习
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
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
        cout << maxPower("triplepillooooow");
    }

    /**
     * 题解
     * @param
     */
    int maxPower(string s)
    {
        int res = 1;
        int maxres = 1;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                res++;
            }
            else
            {
                res = 1;
            }
            if (res > maxres)
            {
                maxres = res;
            }
        }
        return maxres;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
