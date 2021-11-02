//...difficulty:Medium
//...leetcode_22_2021-10-27
//...https://leetcode-cn.com/problems/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

class MinStack
{
    vector<string> res;

public:
    void test()
    {
        generateParenthesis(8);
        for (string i : res)
        {
            cout << i << endl;
        }
    }
    vector<string> generateParenthesis(int n)
    {
        string cur;
        stack<char> hogo;
        check(2 * n, hogo, cur);
        return res;
    }
    void check(int pos, stack<char> hogo, string cur)
    {
        //cout << "pos..." << pos << " cur..." << cur << " T" << endl;
        if (pos == 0)
        {
            if (hogo.empty())
            {
                res.push_back(cur);
            }
            return;
        }
        if ((pos % 2 != 0 && hogo.empty()) || hogo.size() > pos)
        {
            return;
        }
        hogo.push('(');
        check(pos - 1, hogo, cur + '(');
        hogo.pop();
        if (!hogo.empty() && hogo.top() != ')')
        {
            hogo.pop();
            check(pos - 1, hogo, cur + ')');
        }
    }
};

int main()
{
    MinStack solu;
    solu.test();
    return 0;
}
