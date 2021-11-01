//...difficulty:Medium
//...leetcode_47_2021-10-28
//...https://leetcode-cn.com/problems/permutations-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
    set<vector<int>> hogo;
    vector<vector<int>> res;

public:
    Solution()
    {
    }
    void test()
    {
        vector<int> test = {1, 1, 2};
        permuteUnique(test);
        for (auto i : res)
        {
            for (auto j : i)
            {
                cout << j;
            }
            cout << endl;
        }
    }
    void dfs(vector<int> nums, vector<int> ans)
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
            ans.push_back(nums[i]);
            nums.erase(nums.begin() + i);
            dfs(nums, ans);
            nums.insert(nums.begin() + i, ans.back());
            ans.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<int> ans;
        dfs(nums, ans);
        return res;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
