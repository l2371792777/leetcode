/**
 * @description leetcode练习
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <set>
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
    }

    /**
     * 判断是否有重复字母
     * @param word1
     * @param word2
     * return
     */
    bool isHasEqual(string word1, string word2)
    {
        set<char> cur1;
        set<char> cur2;
        for (auto i : word1)
        {
            cur1.insert(i);
        }
        for (auto i : word2)
        {
            if (cur1.find(i) != cur1.end())
            {
                return true;
            }
            cur2.insert(i);
        }
        for (auto i : word1)
        {
            if (cur2.find(i) != cur2.end())
            {
                return true;
            }
        }
        return false;
    }

    /**
     * 题解
     * @param
     */
    int maxProduct(vector<string> &words)
    {
        int lengthmax = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                int mul = words[i].size() * words[j].size();
                if (mul > lengthmax && !isHasEqual(words[i], words[j]))
                {
                    lengthmax = mul;
                }
            }
        }
        return lengthmax;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
