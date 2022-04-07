/**
 * @description leetcode练习
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
        vector<int> test={3,3,5,0,0,3,1,4};
        int ret=maxProfit(test);
        cout<<ret;
    }

    /**
     * 题解
     * @param
     */
    int maxProfit(vector<int>& prices) {
        int size=prices.size()-1;
        int ret_Max=0;
        int ret_Min=0;
        int Max=prices[size];
        int Min=Max;
        for(int i=size-1;i>=0;i--){
            if(prices[i]>Max){
                Max=prices[i];
                Min=Max;
            }
            else if(prices[i]<Min){
                Min=prices[i];
                if((Max-Min)>(ret_Max-ret_Min)){
                     ret_Max=Max;
                     ret_Min=Min;
                }
            }
        }
        return ret_Max-ret_Min;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
