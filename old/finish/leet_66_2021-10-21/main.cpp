//...leetcode_66_2021-10-21
//...https://leetcode-cn.com/problems/ayanami5201314
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int length = digits.size();
        int carry = 0;

        if (digits[length - 1] == 9)
        {
            for (int i = length - 1; i >= 0; i--)
            {
                cout<<"old..."<<digits[i];
                if (digits[i] == 9)
                {
                    digits[i] = 0;
                    if (i == 0)
                    {
                        digits.insert(digits.begin(), 1);
                    }
                }
                else
                {
                    digits[i] += 1;
                    return digits;
                }
                cout<<" new..."<<digits[i]<<endl;
            }
        }
        else
        {
            digits[length - 1] += 1;
        }
        return digits;
    }
};

int main()
{
    test();
    return 0;
}

void test()
{
    Solution test;
    vector<int> digits = {7899};
    digits = test.plusOne(digits);
    for (int i : digits)
    {
        cout <<"a... "<< i << endl;
    }
}