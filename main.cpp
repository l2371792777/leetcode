#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
#include <cmath>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    void test()
    {
        vector<int> test = {5, 7, 7, 8, 8, 10};
        cout << missingNumber(test);
    }
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += i;
        }
        for (int i : nums)
        {
            sum -= i;
        }
        return sum;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
