## 100298.反转链表
Easy  
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

 

示例:

```
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
```

 

限制：

``0 <= 节点个数 <= 5000``

 

注意：本题与主站 206 题相同：<a href="https://leetcode-cn.com/problems/reverse-linked-list/">https://leetcode-cn.com/problems/reverse-linked-list/</a>

### 题解:  
* 思路  
    三个指针标记当前节点，父节点，next节点  
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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
        {
            return head;
        }
        ListNode *root = head->next;
        ListNode *pnext = NULL;
        head->next = NULL;
        while (root != NULL)
        {
            pnext = root->next;
            root->next = head;
            head = root;
            root = pnext;
            if (pnext != NULL)
            {
                pnext = pnext->next;
            }
        }
        return head;
    }
};
```