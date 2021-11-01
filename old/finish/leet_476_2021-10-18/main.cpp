//...leetcode_476_2021-10-18
//...https://leetcode-cn.com/problems/number-complement/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int findComplement(int num);
void pintfBinary(int num);

int main()
{
    test();
    return 0;
}

void test()
{
    int t = findComplement(0);
    cout << t;
}

int findComplement(int num)
{
    //低位置一
    int t = num;
    t |= t >> 1;
    t |= t >> 2;
    t |= t >> 4;
    t |= t >> 8;
    t |= t >> 16;
    return num ^ t;
}

void pintfBinary(int num)
{
    cout << num << " | ";
    while (num > 1)
    {
        cout << num % 2;
        num /= 2;
    }
    cout << num << endl;
}