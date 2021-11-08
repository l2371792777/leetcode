## 100276.二维数组中的查找
Medium  
在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

 

示例:

现有矩阵 matrix 如下：

```

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

```

给定 target = ``5``，返回 ``true``。

给定 target = ``20``，返回 ``false``。

 

限制：

``0 <= n <= 1000``

``0 <= m <= 1000``

 

注意：本题与主站 240 题相同：<a href="https://leetcode-cn.com/problems/search-a-2d-matrix-ii/">https://leetcode-cn.com/problems/search-a-2d-matrix-ii/</a>

### 题解:  
* 思路  
从右上开始判断，`matix<target`下移，`matrix>target`左移  
状态不同选择不同，若从左上开始，无法判断下一个状态
* 代码  
```c++
  bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
    {
        if(matrix.empty())
        {
            return false;
        }
        int m = 0;
        int n = matrix[0].size() - 1;
        while (m < matrix.size() && n >= 0)
        {
            if (matrix[m][n] == target)
            {
                return true;
            }
            else if(matrix[m][n] > target)
            {
                n++;
            }
            else if(matrix[m][n] < target)
            {
                m--;
            }
        }
        return false;
    }
```