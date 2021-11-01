//...leetcode_639_2021-09-27
//...https://leetcode-cn.com/problems/decode-ways-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int numDecodings(string s);

int main()
{
    test();
    return 0;
}

void test()
{
    string hogo = "***********";
    cout << numDecodings(hogo);
}

int numDecodings(string s)
{
    //动态规划
    int n = s.size();
    vector<long long> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << " i... " << i << " s[i-1]... " << s[i - 1] << " dp[i-1]... " << dp[i - 1];
        //s[i]
        if (s[i - 1] == '*')
        {
            dp[i] = dp[i - 1] * 9;
        }
        else if (s[i - 1] == '0')
        {
        }
        else
        {
            dp[i] = dp[i - 1];
        }
        if (i < 2)
        {
            dp[i]=dp[i]%(1000000000+7);
            cout << endl;
            continue;
        }
        //s[i-1]s[i]
        if (s[i - 2] == '*' && s[i - 1] == '*')
        {
            dp[i] = dp[i] + dp[i - 2] * 15;
        }
        else if (s[i - 2] == '*')
        {
            if (s[i - 1] <= '6')
            {
                dp[i] = dp[i] + dp[i - 2] * 2;
            }
            else
            {
                dp[i] = dp[i] + dp[i - 2];
            }
        }
        else if (s[i - 1] == '*')
        {
            if (s[i - 2] == '1')
            {
                dp[i] = dp[i] + dp[i - 2] * 9;
            }
            else if (s[i - 2] == '2')
            {
                dp[i] = dp[i] + dp[i - 2] * 6;
            }
        }
        else if (s[i - 2] != '0' && ((s[i - 2] == '2' && s[i - 1] <= '6')||(s[i - 2] == '1' && s[i - 1] <= '9')))
        {
            dp[i] = dp[i] + dp[i - 2];
        }
        dp[i]=dp[i]%(1000000000+7);
        cout << " dp[i]... " << dp[i] << endl;
    }

    return dp[n]%(1000000000+7);
}