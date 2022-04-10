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
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *left;
    ListNode *right;
    ListNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    ListNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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
    }

    /**
     * 题解
     * @param
     */
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int size=0;
        ListNode* node=head;
        while(node!=NULL){
            node=node->next;
            size++;
        }
        node=head;
        int n=1;
        while(n!=size-k){
            node=node->next;
            n++;
        }
        return node;
    }
};

int main()
{
    // Solution solu;
    // solu.test();
    return 0;
}
