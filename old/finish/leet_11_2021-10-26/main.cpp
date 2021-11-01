//...leetcode_11_2021-10-26
//...https://leetcode-cn.com/problems/container-with-most-water/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

class Solution
{
public:
    void test()
    {
    }
    int maxArea(vector<int> &height)
    {
        int begin = 0;
        int end = height.size() - 1;
        int res = 0;
        int h = 0;
        while (begin < end)
        {
            int b = begin;
            int e = end;
            if (height[b] > height[e])
            {
                h = height[e];
                end--;
            }
            else
            {
                h = height[b];
                begin++;
            }
            int container = h * (e - b);
            if (res < container)
            {
                res = container;
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
