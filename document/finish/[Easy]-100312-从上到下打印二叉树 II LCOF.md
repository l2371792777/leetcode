## 100312.从上到下打印二叉树 II
Easy  
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

 

例如:<br>
给定二叉树: ``[3,9,20,null,null,15,7]``,

```
    3
   / \
  9  20
    /  \
   15   7

```

返回其层次遍历结果：

```
[
  [3],
  [9,20],
  [15,7]
]

```

 

提示：

<ol>
	<li>``节点总数 <= 1000``</li>
</ol>

注意：本题与主站 102 题相同：<a href="https://leetcode-cn.com/problems/binary-tree-level-order-traversal/">https://leetcode-cn.com/problems/binary-tree-level-order-traversal/</a>

### 题解:  
* 思路  
先序遍历，记录节点高度，存入相应数组
* 代码  
```c++
class Solution
{
    vector<vector<int>> res;

public:
    void test()
    {
    }
    void dfs(TreeNode *root, int h)
    {
        if (root == NULL)
        {
            return;
        }
        if (res.size() < (h + 1))
        {
            vector<int> temp;
            res.push_back(temp);
        }
        res[h].push_back(root->val);
        dfs(root->left, h + 1);
        dfs(root->right, h + 1);
    }
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        dfs(root, 0);
        return res;
    }
};

```