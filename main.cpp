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
        cout << findNthDigit(1000000000);
    }

    /**
     * 题解
     * @param
     */
    int findNthDigit(int n)
    {
        int pos = 1; //判断位数
        long long digits = 9;
        long long num = 0; //每位占据数字个数
        while (n)
        {
            num = pos * digits;
            cout << num << endl;
            if (n <= num)
            {
                break;
            }
            pos++;
            digits *= 10;
            n = n - num;
        }
        //第几个数字
        int offset = (n - 1) / pos;
        cout <<"offset... "<< offset << endl;
        //获取位数最小数字
        int beginDigit = 1;
        for (int i = 0; i < pos - 1; i++)
        {
            beginDigit *= 10;
        }
        //数字内位数
        int mod = (n - 1) % pos;
        cout <<"mod... "<< mod << endl;
        string resDigit = to_string(beginDigit + offset);
        cout <<"resDigit... "<< resDigit << endl;
        return resDigit[mod] - '0';
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
