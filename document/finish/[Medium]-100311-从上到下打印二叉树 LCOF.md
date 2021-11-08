## 100311.从上到下打印二叉树
Medium  
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

 

例如:<br>
给定二叉树: ``[3,9,20,null,null,15,7]``,

```
    3
   / \
  9  20
    /  \
   15   7

```

返回：

```
[3,9,20,15,7]

```

 

提示：

<ol>
	<li>``节点总数 <= 1000``</li>
</ol>

### 题解:  
* 思路  
参考官方题解  
层序遍历，将叔存入队列
* 代码  
```c++
class Solution
{
    vector<int> res;
    queue<TreeNode *> hogo;

public:
    void test()
    {
    }
    vector<int> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return res;
        }
        hogo.push(root);
        while (!hogo.empty())
        {
            res.push_back(hogo.front()->val);
            if (hogo.front()->left != NULL)
            {
                hogo.push(hogo.front()->left);
            }
            if (hogo.front()->right != NULL)
            {
                hogo.push(hogo.front()->right);
            }
            hogo.pop();
        }
        return res;
    }
};
```