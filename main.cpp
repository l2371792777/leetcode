#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void test()
    {
        vector<int> test = {1, 4};
        int d = 2;
        cout << findPoisonedDuration(test, d);
    }
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int res = 0;

        for (int i = 0; i < timeSeries.size(); i++)
        {
            if (i == timeSeries.size() - 1 || timeSeries[i] + duration - 1 < timeSeries[i+1])
            {
                res += duration;
            }
            else if (timeSeries[i] + duration - 1 >= timeSeries[i+1])
            {
                res = res + timeSeries[i + 1] - timeSeries[i];
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
