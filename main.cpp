/**
 * @description leetcode练习
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>
#include <set>

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
     * 这是测试
     * @param
     */
    void test()
    {
        vector<int> res=grayCode(3);
        cout<<endl;
        for(int i : res){
            cout<<i<<" ";
        }
    }

    /**
     * 题解
     * @param
     */
    vector<int> grayCode(int n) {
        if(n==1){
            return {0,1};
        }
        int Gmax=pow(2,n)-1;
        vector<int> res(Gmax+1);
		res[0]=0;
		res[Gmax]=2;
        for(int i=0;i<=Gmax/2;i++){
            
        }
        return res;
    }
};

int main()
{
    Solution solu;
    solu.test();
    return 0;
}
