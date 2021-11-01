//...leetcode_29_2021-10-12
//...https://leetcode-cn.com/problems/divide-two-integers/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int divide(int dividend, int divisor);
int redivide(long a, long b);

int main()
{
    test();
    return 0;
}

void test()
{
    cout << divide(-7, -3);
}

int redivide(long a, long b)
{
    if (a < b)
        return 0;
    long res = 1;
    long temp = b;
    while ((temp + temp) <= a)
    {
        temp += temp;
        res += res;
    }
    res += redivide(a - temp, b);
    return res;
}

int divide(int dividend, int divisor)
{
    int max = 2147483647;
    int min = -2147483648;
    if (dividend == min && divisor == -1)
    {
        return max;
    }
    if (dividend == 0)
    {
        return 0;
    }
    bool sign = true;
    if (!((dividend >= 0 && divisor >= 0) || (dividend < 0 && divisor < 0)))
    {
        sign = false;
    }
    long a = dividend, b = divisor;
    a = a > 0 ? a : 0 - a;
    b = b > 0 ? b : 0 - b;
    long res = redivide(a, b);
    if (sign)
    {
        return res;
    }
    return 0 - res;
}