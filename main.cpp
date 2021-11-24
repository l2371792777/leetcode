/**
 * @description leetcode练习
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
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
public:
    /**
     * 测试
     * @param
     */
    void test()
    {
        string test = "zeroonetwothreefourfivesixseveneightnine";
        cout << originalDigits(test);
    }

    /**
     * 题解
     * @param
     */
    string originalDigits(string s)
    {
        map<char, int> c;
        for (char ch: s) {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans += char(i + '0');
            }
        }
        return ans;

    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
