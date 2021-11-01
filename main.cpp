#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    void test()
    {
        vector<int> test = {2, 1, 1, 3};
        cout << distributeCandies(test);
    }
    int distributeCandies(vector<int> &candyType)
    {
        set<int> candy;
        for (int i : candyType)
        {
            if (candy.find(i) == candy.end())
            {
                candy.insert(i);
            }
        }
        int account = candy.size();
        int nums = candyType.size();
        if (account > nums / 2)
        {
            return nums / 2;
        }
        else
        {
            return account;
        }
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
