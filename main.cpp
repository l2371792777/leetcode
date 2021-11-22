/**
 * @description leetcode练习
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

/**
 * 二叉树
 */
struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
    vector<int> cur;

public:
    /**
     * 测试
     * @param
     */
    void test()
    {
        vector<int> test = reset();
        for (auto i : test)
        {
            cout << i << " ";
        }
        cout << endl;
        test=shuffle();
        for (auto i : test)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    /**
     * 题解
     * @param nums 无重复数组
     */
    Solution(vector<int> &nums)
    {
        cur = nums;
    }

    vector<int> reset()
    {
        return cur;
    }

    vector<int> shuffle()
    {
        vector<int> tmp = cur;
        vector<int> res;
        int n, i;
        while (!tmp.empty())
        {
            n = tmp.size();
            i = rand() % n;
            res.push_back(tmp[i]);
            tmp.erase(tmp.begin() + i);
        }
        return res;
    }
};

int main()
{
    vector<int> res = {1, 2, 3, 4, 5, 6};
    Solution solu(res);
    solu.test();
    return 0;
}
