//...leetcode_20_2021-10-27
//...https://leetcode-cn.com/problems/valid-parentheses/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

class Solution
{
public:
    void test()
    {
    }
    bool isValid(string s)
    {
        stack<char> hogo;
        for (char i : s)
        {
            if (!hogo.empty() && ((hogo.top() == '(' && i == ')') || (hogo.top() == '[' && i == ']') || (hogo.top() == '{' && i == '}')))
            {
                hogo.pop();
                continue;
            }
            hogo.push(i);
        }
        if (hogo.empty())
        {
            return true;
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
