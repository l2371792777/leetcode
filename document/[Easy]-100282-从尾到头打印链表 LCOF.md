## 100282.从尾到头打印链表
Easy  
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

 

示例 1：

```
输入：head = [1,3,2]
输出：[2,3,1]
```

 

限制：

``0 <= 链表长度 <= 10000``

### 题解:  
* 思路  
创建等同节点个数的数组，按号入座

* 代码  
```  
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode *head)
    {
        ListNode *root = head;
        int num = 0;
        while (root != NULL)
        {
            num++;
            root = root->next;
        }
        vector<int> res(num);
        while (head != NULL)
        {
            res[num - 1] = head->val;
            head = head->next;
            num--;
        }
        return res;
    }
};
```