## 100299.删除链表的节点
``difficulty``:``Easy``  
<hr>
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

```
输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.

```

示例 2:

```
输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

```

 

说明：

<ul>
	<li>题目保证链表中节点的值互不相同</li>
	<li>若使用 C 或 C++ 语言，你不需要 ``free`` 或 ``delete`` 被删除的节点</li>
</ul>

### 题解:  
* 思路  

* 代码  
```c++
	struct ListNode
	{
    	int val;
    	ListNode *next;
    	ListNode *left;
    	ListNode *right;
    	ListNode() : val(0), left(NULL), right(NULL), next(NULL) {}
    	ListNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
	};
	ListNode* deleteNode(ListNode* head, int val) {
        if(head->val==val){
            return head->next;
        }
        ListNode* node=head->next;
        ListNode* left=head;
        while(node->val!=val){
            left=node;
            node=node->next;
        }
        if(node!=NULL){
            left->next=node->next;
        }
        return head;
    }
```