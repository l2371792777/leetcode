## 100288.二叉树的镜像
Easy  
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

例如输入：


```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```

镜像输出：


```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```


 

示例 1：

```
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]

```

 

限制：


```
0 <= 节点个数 <= 1000
```


注意：本题与主站 226 题相同：<a href="https://leetcode-cn.com/problems/invert-binary-tree/">https://leetcode-cn.com/problems/invert-binary-tree/</a>

### 题解:  
* 思路  

* 代码  
```c++
    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        TreeNode *tmp;
        //交换左右孩子
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        dfs(root->left);
        dfs(root->right);
    }
    TreeNode *mirrorTree(TreeNode *root)
    {
        dfs(root);
        returnroot;
    }
```