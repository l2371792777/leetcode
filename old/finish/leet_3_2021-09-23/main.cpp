//...leetcode_3_2021-09-23
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int lengthOfLongestSubstring(string s);

int main()
{
    test();
    return 0;
}

void test()
{
    cout << lengthOfLongestSubstring("  ");
}

int lengthOfLongestSubstring(string s)
{
    int n = s.size() - 1;
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    //储存出现的字符位置
    vector<int> isexist(128);
    //前两位储存当前标志位，第三，四位储存 最长子串标志位，第五位储存 最长子串长度
    vector<int> sign(5);

    isexist[s[0]] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (isexist[s[i]] != 0 && (isexist[s[i]] - 1) >= sign[0]) //有重复字符 开始位后移
        {
            sign[0] = isexist[s[i]];
        }
        isexist[s[i]] = i + 1;
        sign[1] = i;
        if ((sign[1] - sign[0] + 1) > sign[4])
        {
            sign[4] = sign[1] - sign[0] + 1;
            sign[2] = sign[0];
            sign[3] = sign[1];
        }
    }
    return sign[4];
}