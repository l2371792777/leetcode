//...leetcode_230_2021-10-17
//...https://leetcode-cn.com/problems/submissions/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *left;
    ListNode *right;
    ListNode() : val(0), left(nullptr), right(nullptr) {}
    ListNode(int x) : val(x), left(nullptr), right(nullptr) {}
    ListNode(int x, ListNode *left, ListNode *right) : val(x), left(left), right(right) {}
};
void test();
int kthSmallest(ListNode *root, int k);

int main()
{
    test();
    return 0;
}

void test()
{
}
int account = 0;
int ans = -1;
int kthSmallest(ListNode *root, int k)
{
    dfs(root, k);
    return ans;
}

void dfs(ListNode *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    dfs(root->left, k);
    account++;
    if (account == k)
    {
        ans = root->val;
    }
    dfs(root->right, k);
}