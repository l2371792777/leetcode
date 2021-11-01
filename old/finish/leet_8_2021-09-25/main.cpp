//...leetcode_test_2021-09-25
//...https://leetcode-cn.com/problems
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int myAtoi(string s);

int main()
{
    test();
    return 0;
}

void test()
{
    string cur = "-91283472332";
    cout << endl
         << myAtoi(cur);
}

int myAtoi(string s)
{
    int n = s.size();
    int res = 0;
    int max = 2147483647;

    int i = 0;
    bool sign = true;
    while (s[i] == ' ')
    {
        i++;
    }
    if (s[i] == '-')
    {
        sign = false;
        max = 0 - max - 1;
        i++;
    }
    else if (s[i] == '+')
    {
        i++;
    }
    //cout << "sign.." << sign << " max.." << max << endl;
    while (isdigit(s[i]))
    {
        //cout << "i.." << i << " s[i].." << s[i];
        if (sign && (res >= max / 10))
        {
            if ((s[i] - '0') >= (max % 10) || res > max / 10)
                return max;
        }
        else if (!sign && (res >= 0 - max / 10))
        {
            if ((s[i] - '0') >= (0 - max % 10) || (res > 0 - max / 10))
                return max;
        }
        //cout << " res_new.." << res;
        res = res * 10 + (s[i] - '0');
        //cout << " res_old.." << res << endl;
        i++;
    }
    if (!sign)
    {
        return 0 - res;
    }
    return res;
}