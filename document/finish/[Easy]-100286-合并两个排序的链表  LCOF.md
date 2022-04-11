## 100286.合并两个排序的链表
``difficulty``:``Easy``  
<hr>
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

示例1：

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

限制：

``0 <= 链表长度 <= 1000``

注意：本题与主站 21 题相同：<a href="https://leetcode-cn.com/problems/merge-two-sorted-lists/">https://leetcode-cn.com/problems/merge-two-sorted-lists/</a>

### 题解:  
* 思路  

* 代码  
```c++
    ListNode* head=new ListNode(0);
        ListNode* root=head;
        while(l1!=NULL&&l2!=NULL){
            if(l1->val<l2->val){
                cout<<"root->next--->l1 ";
                cout<<"l1->val_ "<<l1->val<<endl;
                root->next=l1;
                l1=l1->next;
            }
            else{
                cout<<"root->next--->l2 ";
                cout<<"l2->val_ "<<l2->val<<endl;
                root->next=l2;
                l2=l2->next;
            }
            root=root->next;
        }
        root->next=l1?l1:l2;
        return head->next;
```