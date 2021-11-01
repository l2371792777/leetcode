//...leetcode_453_2021-10-20
//...https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
class Solution
{
public:
    int minMoves(vector<int> &nums);
};

int main()
{
    test();
    return 0;
}

void test()
{
    vector<int> nums = {1, 2, 3};
    Solution test;
    cout << test.minMoves(nums);
}

int Solution::minMoves(vector<int> &nums)
{
    long res = 0;
    int min = INT_MAX;
    for (int i : nums)
    {
        if (min > i)
        {
            min = i;
        }
    }
    cout << min << endl;
    for (int i : nums)
    {
        res += i - min;
    }

    return res;
}