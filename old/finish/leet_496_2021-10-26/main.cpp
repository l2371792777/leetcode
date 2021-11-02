//...leetcode_496_2021-10-26
//...https://leetcode-cn.com/problems/next-greater-element-i/
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

class MinStack
{
public:
    void test()
    {
    }
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> ans;
        stack<int> nge;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!nge.empty() && nums2[i] > nge.top())
            {
                nge.pop();
            }
            if (nge.empty())
            {
                ans[nums2[i]] = -1;
            }
            else
            {
                ans[nums2[i]] = nge.top();
            }
            nge.push(nums2[i]);
        }

        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); i++)
        {
            res[i] = ans[nums1[i]];
        }
        return res;
    }
};

int main()
{
    MinStack solu;
    solu.test();
    return 0;
}
