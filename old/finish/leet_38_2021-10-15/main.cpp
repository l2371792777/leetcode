//...leetcode_38_2021-10-15
//...https://leetcode-cn.com/problems/count-and-say/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
string countAndSay(int n);

int main()
{
    test();
    return 0;
}

void test()
{
    cout << countAndSay(3);
}

string countAndSay(int n)
{
    string res = "1";
    string res_temp = res;
    int num, m;
    char temp;
    for (int i = 2; i <= n; i++)
    {
        res_temp = res;
        res = "";
        num = 0;
        m = res_temp.size();
        temp = res_temp[0];;
        for (int j = 0; j <= m; j++)
        {
            if (res_temp[j] == temp && j != m)
            {
                num++;
            }
            else
            {
                res = res + to_string(num) + temp;
                num = 1;
                temp = res_temp[j];
                //cout<<"res "<<res<<endl;
            }
        }
    }
    return res;
}