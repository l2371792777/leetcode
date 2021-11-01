//...leetcode_12_2021-10-26
//...https://leetcode-cn.com/problems/integer-to-roman/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution
{
    map<int, string> hogo;

public:
    Solution()
    {
        hogo[1] = 'I';
        hogo[4] = "IV";
        hogo[5] = 'V';
        hogo[9] = "IX";
        hogo[10] = 'X';
        hogo[40] = "XL";
        hogo[50] = 'L';
        hogo[90] = "XC";
        hogo[100] = 'C';
        hogo[400] = "CD";
        hogo[500] = 'D';
        hogo[900] = "CM";
        hogo[1000] = 'M';
    }
    void test()
    {
        cout << intToRoman(1994);
    }

    string intToRoman(int num)
    {
        vector<int> inter = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        string res;
        for (int i = 12; i >= 0; i--)
        {
            while (num >= inter[i])
            {
                num -= inter[i];
                res += hogo[inter[i]];
            }
        }
        return res;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
