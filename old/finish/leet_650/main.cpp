#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
}

// 动态规划

int minSteps(int n)
{
    vector<int> f(n + 1);
    for (int i = 2; i <= n; i++)
    {
        f[i] = INT_MAX-1;
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                f[i] = min(f[i], f[i / j] + j);
                f[i] = min(f[i], f[j] + i / j);
            }
        }
    }
    return f[n];
}
