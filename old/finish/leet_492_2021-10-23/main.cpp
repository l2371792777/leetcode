//...leetcode_492_2021-10-23
//...https://leetcode-cn.com/problems/submissions
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

void test();
class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int w = sqrt(area);
        while (area % w)
        {
            w--;
        }
        return {area / w, w};
    }

    void test()
    {
        vector<int> hogo;
        hogo = constructRectangle(6);
        for (int i : hogo)
        {
            cout << i << endl;
        }
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
