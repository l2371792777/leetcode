#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size() - 1;
    vector<int> nl(n + 1);
    vector<int> nt(n + 1);
    int max_num = 0;
    int res = 0;

    for (int i = 0; i <= n; i++)
    {
        nl[i] = 1;
        nt[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (nl[i] < nl[j] + 1)
                {
                    nl[i] = nl[j] + 1;
                    nt[i] = nt[j];
                }
                else if (nl[i] == nl[j] + 1)
                {
                    nt[i] += nt[j];
                }
            }
        }
        if (nl[i] > max_num)
        {
            max_num = nl[i];
            res = nt[i];
        }
        else if (nl[i] == max_num)
        {
            res += nt[i];
        }
    }
    return res;
}

int findNumberOfLIS_old(vector<int> &nums)
{
    int n = nums.size() - 1;
    int result = 0;
    int num_max = 1;
    vector<int> f(n + 1);

    for (int i = 0; i <= n; i++)
    {
        f[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] == nums[j])
            {
                continue;
            }
            if (nums[i] > nums[j])
            {
                f[i] = max(f[i], f[j] + 1);
            }
            if (f[i] > num_max)
            {
                num_max = f[i];
                result = 1;
            }
            else if (f[i] == num_max)
            {
                result++;
            }
        }
        if (f[i] == 1)
        {
            result++;
        }
    }
    return result;
}

void test()
{
    //[1,2,4,3,5,4,7,2]
    vector<int> test = {1, 2, 4, 3, 5, 4, 7, 2};
    cout << findNumberOfLIS(test);
}

int main()
{
    test();
    return 0;
}