//...difficulty:Medium
//...leetcode_869_2021-10-28
//...https://leetcode-cn.com/problems/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <set>
#include <cmath>

using namespace std;

class Solution
{
    set<int> hogo;
    vector<int> res;

public:
    void test()
    {
        cout << reorderedPowerOf2(2);
        for (auto i : res)
        {
            cout << i << endl;
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

    void dfs(vector<int> nums, int ans)
    {
        if (nums.size() == 0)
        {
            if (hogo.count(ans) == 0)
            {
                hogo.insert(ans);
                res.push_back(ans);
            }
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 && nums[i] == 0)
            {
                continue;
            }
            ans = ans * 10 + nums[i];
            nums.erase(nums.begin() + i);
            dfs(nums, ans);
            nums.insert(nums.begin() + i, ans % 10);
            ans = ans / 10;
        }
    }
    bool check()
    {
        for (int i : res)
        {
            if (isPowerOfTwo(i))
            {
                return true;
            }
        }
        return false;
    }
    bool reorderedPowerOf2(int n)
    {
        vector<int> nums;
        int ans;
        while (n)
        {
            nums.push_back(n % 10);
            n = n / 10;
        }
        dfs(nums, ans);
        return check();
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
