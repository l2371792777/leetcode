//...leetcode_273_2021-10-11
//...https://leetcode-cn.com/problems/integer-to-english-words/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
string numberToWords(int num);

int main()
{
    test();
    return 0;
}

void test()
{
    cout << numberToWords(1000010);
}

string numberToWords(int num)
{
    //３个数字一组
    //确认间隔点
    vector<string> cur1_gt20 = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen", "Twenty"};
    vector<string> cur2_gt100 = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> cur3_gt1000 = {"", "One Hundred", "Two Hundred", "Three Hundred", "Four Hundred", "Five Hundred", "Six Hundred", "Seven Hundred", "Eight Hundred", "Nine Hundred"};
    vector<string> cur4_sign = {"Thousand", "Million", "Billion"};
    string res_hogo = "";
    string res="";
    
    int sign = 0;

    if (num <= 20)
    {
        return cur1_gt20[num];
    }
    cur1_gt20[0] = "";
    while (num != 0)
    {
        res_hogo="";
        string empty = "";
        if (res_hogo != empty)
        {
            empty = " ";
        }
        int part = num % 100;
        if (part <= 20)
        {
            res_hogo = cur1_gt20[part] + res_hogo;
        }
        else if (part > 20)
        {
            res_hogo = cur1_gt20[part % 10] + res_hogo;
            if (res_hogo != empty)
            {
                empty = " ";
            }
            res_hogo = cur2_gt100[part / 10] + empty + res_hogo;
        }
        num = num / 100;
        part = num % 10;
        if (res_hogo != empty)
        {
            empty = " ";
        }
        if (part != 0)
        {
            res_hogo = cur3_gt1000[part] + empty + res_hogo;
        }
        num = num / 10;
        if (res_hogo != empty)
        {
            empty = " ";
        }
        if (num != 0&&num%1000>0)
        {
            res_hogo = " " + cur4_sign[sign] + empty + res_hogo;    
        }
        sign++;
        res=res_hogo+res;
    }
    return res;
}