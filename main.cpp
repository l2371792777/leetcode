#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
#include <cmath>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    void test()
    {
        cout << getHint("1122", "1222");
    }
    string getHint(string secret, string guess)
    {
        map<char, int> hogo;
        map<char, int> hogs;
        for (int i = 0; i < secret.size(); i++)
        {
            hogo[secret[i]]++;
            hogs[guess[i]]++;
        }
        int A = 0, B = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                A++;
                hogo[secret[i]]--;
                hogs[secret[i]]--;
            }
			else if (hogo[guess[i]] != 0 && hogs[guess[i]] != 0)
            {
                B++;
                hogo[guess[i]]--;
                hogs[guess[i]]--;
            }
        }

        return to_string(A) + 'A' + to_string(B) + 'B';
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
