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

class MapSum
{
    map<string, int> sums;
    map<string, int> cur;

public:
    void test()
    {
    }
    MapSum()
    {
    }

    void insert(string key, int val)
    {
        string tmp = "";
        if (cur.find(key) != cur.end())
        {
            //若已存在，删除当前存储值
            for (auto i : key)
            {
                tmp += i;
                sums[tmp] -= cur[key];
            }
        }
        cur[key]=val;
        tmp = "";
        for (auto i : key)
        {
            tmp += i;
            sums[tmp] += val;
        }
    }

    int sum(string prefix)
    {
        return sums[prefix];
    }
};

int main()
{
    MapSum solu;
    solu.test();
    return 0;
}
