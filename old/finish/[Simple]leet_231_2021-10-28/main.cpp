//...difficulty:Simple
//...leetcode_231_2021-10-28
//...https://leetcode-cn.com/problems/power-of-two/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

class MinStack
{
public:
    void test()
    {
        for (int i = 0; i < 100; i++)
        {
            cout << "i... " << i << " " << isPowerOfTwo(i) << endl;
        }
    }
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
        {
            return false;
        }
        while (n)
        {
            if (n == 1)
            {
                return true;
            }
            if (n % 2 != 0)
            {
                return false;
            }
            n = n / 2;
        }
        return true;
    }
};

int main()
{
    MinStack solu;
    solu.test();
    return 0;
}
