/**
 * @description leetcode练习
 * @author lyc
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
        cout<<lengthOfLongestSubstring("pwwkew");
    }

    /**
     * 题解
     * @param
     */
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n <= 1)
        {
            return n;
        }
        //储存出现的字符位置
        vector<int> charPosition(128,-1);
        //0,1储存当前标志位，2,3储存 最长子串标志位，4储存 最长子串长度
        vector<int> sign(5);

        charPosition[s[0]] = 0;
        for (int i = 1; i < n; i++)
        {
            //有重复字符 左侧指针后移
            if (charPosition[s[i]] >= 0 && charPosition[s[i]] >= sign[0]) 
            {
                sign[0] = charPosition[s[i]]+1;
            }
            charPosition[s[i]] = i;
            sign[1] = i;
            if ((sign[1] - sign[0] + 1) > sign[4])
            {
                sign[4] = sign[1] - sign[0] + 1;
                sign[2] = sign[0];
                sign[3] = sign[1];
            }
        }

        return sign[4];
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
