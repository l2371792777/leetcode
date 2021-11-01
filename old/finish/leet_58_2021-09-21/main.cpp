#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

void test();
int lengthOfLastWord(string s);

int main()
{
    test();
    return 0;
}

int lengthOfLastWord(string s)
{
    int n = s.size() - 1;
    int result = 0;
    for (int i = n; i >= 0; i--)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            result++;
        }
        else if (result != 0)
        {
            break;
        }
        else
        {
            result = 0;
        }
    }
    return result;
}

void test()
{
    string cur = "aasad asdasda adsaasd  asd ";
    cout << lengthOfLastWord(cur);
}