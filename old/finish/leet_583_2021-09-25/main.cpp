//...leetcode_583_2021-09-25
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int minDistance(string word1, string word2);

int main()
{
    test();
    return 0;
}

void test()
{
    string word1 = "aswd";
    string word2 = "sdwqe";
    cout << minDistance(word1, word2);
}

int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    int res = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 1; i <= m; i++)
    {
        char cur1 = word1[i - 1];
        for (int j = 1; j <= n; j++)
        {
            char cur2 = word2[j - 1];
            if (cur1 == cur2)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    res = dp[m][n];
    return m + n - 2 * res;
}
