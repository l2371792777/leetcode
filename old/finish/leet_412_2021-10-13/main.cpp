//...leetcode_412_2021-10-13
//...https://leetcode-cn.com/problems/fizz-buzz/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
vector<string> fizzBuzz(int n);

int main()
{
    test();
    return 0;
}

void test()
{
    cout<<fizzBuzz(15)[1];
}

vector<string> fizzBuzz(int n)
{
    vector<string> answer(n);
    for(int i=1;i<=n;i++)
    {
        if(i%3==0)
        {
            answer[i-1]+="Fizz";
        }
        if(i%5==0)
        {
            answer[i-1]+="Buzz";
        }
        if(i%3!=0&&i%5!=0){
            answer[i-1]+=to_string(i);
        }
    }
    return answer;
}