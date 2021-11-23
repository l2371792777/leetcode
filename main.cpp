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
        string test1 = "aabcaaa";
        string test2 = "aabcaaa";
        cout << "test..." << endl;
        cout << buddyStrings(test1, test2);
    }

    /**
     * 题解
     * @param
     */
    bool buddyStrings(string s, string goal)
    {
        if(s.size()!=goal.size())
        {
            return false;
        }
        
        if (s == goal)
        {
            //统计单词出现个数
            vector<int> words(26);
            for (auto i : s)
            {
                words[i - 'a']++;
                if (words[i - 'a'] > 1)
                {
                    return true;
                }
            }
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == goal[i])
            {
                continue;
            }
            for (int j = i + 1; j < s.size(); j++)
            {
                swap(s[i], s[j]);
                if (s == goal)
                {
                    return true;
                }
                swap(s[i], s[j]);
            }
        }

        return false;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
