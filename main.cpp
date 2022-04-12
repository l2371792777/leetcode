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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *left;
    ListNode *right;
    ListNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    ListNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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
        string test = "  hello world!  ";
        test = reverseWords(test);
        cout << endl
             << test;
    }

    /**
     * 题解
     * @param
     */
    string reverseWords(string s)
    {
        vector<string> ret;
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (str != "")
                {
                    ret.push_back(str);
                    str = "";
                }
                continue;
            }
            str += s[i];
        }
        if (str[0] != ' ' && str != "")
        {
            ret.push_back(str);
        }
        if(ret.size()==0){
            return "";
        }
        str = ret[ret.size() - 1];
        for (int i = ret.size() - 2; i >= 0; i--)
        {
            cout << "\"" << ret[i] << "\""
                 << " ";
            str = str + " " + ret[i];
        }

        return str;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
