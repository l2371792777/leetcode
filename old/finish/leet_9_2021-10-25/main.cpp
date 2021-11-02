//...leetcode_9_2021-10-25
//...https://leetcode-cn.com/problems/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

class MinStack
{
public:
    void test()
    {
        cout << isPalindrome(10);
    }
    bool isPalindrome(int x)
    {
        if (x >= 0 && x < 10)
        {
            return true;
        }
        if (x < 0 || x % 10 == 0)
        {
            return false;
        }

        int hogo = 0;

        while (hogo < x)
        {
            hogo = hogo * 10 + x % 10;
            x = x / 10;
            cout << hogo << " " << x << endl;
            if (hogo == x)
            {
                return true;
            }
        }
        if (hogo / 10 == x)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    MinStack solu;
    solu.test();
    return 0;
}
