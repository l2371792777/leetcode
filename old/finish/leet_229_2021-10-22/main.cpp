//...leetcode_229_2021-10-22
//...https://leetcode-cn.com/problems/majority-element-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>

using namespace std;

void test();
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> hogo;
        vector<int> res;
        for (int i : nums)
        {
            if (hogo.find(i) == hogo.end())
            {
                hogo[i] = 0;
            }
            hogo[i]++;
            if (hogo[i] > n / 3)
            {
                res.push_back(i);
                hogo[i] -= n;
            }
        }
        return res;
    }
};

int main()
{
    test();
    return 0;
}

void test()
{
}