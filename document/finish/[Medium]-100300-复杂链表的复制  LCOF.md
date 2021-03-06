## 100300.复杂链表的复制
Medium  
请实现 ``copyRandomList`` 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 ``next`` 指针指向下一个节点，还有一个 ``random`` 指针指向链表中的任意节点或者 ``null``。

 

示例 1：

<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e1.png">

```
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

```

示例 2：

<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e2.png">

```
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]

```

示例 3：

<img alt="" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/01/09/e3.png">

```
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]

```

示例 4：

```
输入：head = []
输出：[]
解释：给定的链表为空（空指针），因此返回 null。

```

 

提示：

<ul>
	<li>``-10000 <= Node.val <= 10000``</li>
	<li>``Node.random`` 为空（null）或指向链表中的节点。</li>
	<li>节点数目不超过 1000 。</li>
</ul>

 

注意：本题与主站 138 题相同：<a href="https://leetcode-cn.com/problems/copy-list-with-random-pointer/">https://leetcode-cn.com/problems/copy-list-with-random-pointer/</a>

 

### 题解:  
* 思路  
若无random节点，就是普通的链表复制。
难点在于如何让节点指向不指向原链表。 
拆分原链表节点，使用拆分后的节点生成新链表，random指向拆分后节点。便可保证所有节点指向皆为本链表。
* 代码  
```  
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL)
        {
            return head;
        }
        vector<Node *> hogo;
        vector<Node *> Nhogo;

        Node *root = head;
        while (root != NULL)
        {
            hogo.push_back(root);
            root = root->next;
        }
        root = head;
        int num = 0;
        while (root != NULL)
        {
            Nhogo.push_back(new Node(root->val));
            if (num != 0)
            {
                Nhogo[num - 1]->next = Nhogo[num];
            }
            root = root->next;
            num++;
        }

        root = Nhogo[0];
        while (head != NULL)
        {
            if (head->random != NULL)
            {
                auto it = find(hogo.begin(), hogo.end(), head->random);
                num = it - hogo.begin();
                root->random = Nhogo[num];
            }
            head = head->next;
            root = root->next;
        }
        root = Nhogo[0];
        return root;
    }
};
```