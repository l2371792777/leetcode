//...leetcode_371_2021-09-26
//...https://leetcode-cn.com/problems/submissions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int getSum(int a, int b);

int main()
{
    test();
    return 0;
}

void test()
{
}

int getSum(int a, int b)
{
    while (b != 0)
    {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a = a ^ b;
        b = carry;
    }
    return a;
}
