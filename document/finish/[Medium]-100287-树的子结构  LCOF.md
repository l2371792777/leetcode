## 100287.树的子结构
Medium  
输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:


```
     3
    / \
   4   5
  / \
 1   2
```

给定的树 B：


```
   4 
  /
 1
```

返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

示例 1：

```
输入：A = [1,2,3], B = [3,1]
输出：false

```

示例 2：

```
输入：A = [3,4,5,1,2], B = [4,1]
输出：true
```

限制：


```
0 <= 节点个数 <= 10000
```


### 题解:  
* 思路  
获取所有和B头节点相同的的节点,从上一步获取的节点开始匹配,
* 代码  
```c++
  TreeNode *getroot(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->val == val)
        {
            lroot.push_back(root);
        }
        getroot(root->left, val);
        getroot(root->right, val);
    }
    void getres(TreeNode *A, TreeNode *B, bool &res)
    {
        if (A == NULL && B == NULL)
        {
            return;
        }
        if (A == NULL || B == NULL || A->val != B->val)
        {
            res = false;
            return;
        }
        getres(A->left, B->left, res);
        getres(A->right, B->right, res);
    }
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        if (A == NULL || B == NULL)
        {
            return false;
        }
        TreeNode *root = getroot(A, B->val);
        if (root == NULL)
        {
            return false;
        }
        bool res = true;
        for (auto it : lroot)
        {
            res = true;
            getres(it, B, res);
            if (res)
            {
                return res;
            }
        }
        return false;
    }
```