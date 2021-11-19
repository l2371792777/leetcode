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
        cout << integerReplacement(2000000) << endl;
    }

    /**
     * 题解
     * @param
     */
    int integerReplacement(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        if (n % 2 == 0)
        {
            return 1 + integerReplacement(n / 2);
        }
        else
        {
            return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        }
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
