//...leetcode_offerII069_2021-10-14
//...https://leetcode-cn.com/problems/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int peakIndexInMountainArray(vector<int> &arr);

int main()
{
    test();
    return 0;
}

void test()
{
}

int peakIndexInMountainArray(vector<int> &arr)
{
    int n = arr.size();
    int left = 0, right = n - 1;
    int mid = (left + right) / 2;
    while (!(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]))
    {
        if (arr[mid] > arr[mid - 1])
        {
            left = mid;
            mid = (left + right) / 2;
        }
        else
        {
            right = mid;
            mid = (left + right) / 2;
        }
    }
    return mid;
}