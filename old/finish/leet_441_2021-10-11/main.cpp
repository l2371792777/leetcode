//...leetcode_441_2021-10-11
//...https://leetcode-cn.com/problems/arranging-coins/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int arrangeCoins(int n);

int main()
{
    test();
    return 0;
}

void test()
{
    cout << arrangeCoins(6);
}

int arrangeCoins(int n)
{
    long long res = 0;
    long long nums = 0;
    while (nums < n)
    {
        nums = nums + res + 1;
        res++;
    }
    if (nums == n)
        return res;
    else
        return res - 1;
}