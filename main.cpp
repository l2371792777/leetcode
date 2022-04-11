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
#include <unordered_set>

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (temp != nullptr)
        {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        while (temp != nullptr)
        {
            if (visited.count(temp))
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

int main()
{
    // Solution solu;
    // solu.test();
    return 0;
}
