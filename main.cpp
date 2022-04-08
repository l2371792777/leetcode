/**
 * @description leetcode练习
 * @author lyc
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>

using namespace std;

/**
 * 二叉树
 */
struct TreeNode
{
    int val;
    TreeNode *next;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution
{
public:
    /**
     * 测试
     * @param
     */
    void test()
    {
        vector<vector<int>> test={{1,2,5},{3,2,1}};
        cout<<maxValue(test);
    }

    /**
     * 题解
     * @param
     */
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ret((m+1)*(n+1),0);

        int ret_MAX=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               int pos=n*i+j+i+n+2;
               int pos_up=n*(i-1)+j+(i-1)+n+2;
               int pos_left=pos-1;
               ret[pos]=max(ret[pos_up]+grid[i][j],ret[pos_left]+grid[i][j]);
               ret_MAX=max(ret_MAX,ret[pos]);
            }
        }
        return ret_MAX;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
