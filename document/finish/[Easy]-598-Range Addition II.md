## 598.范围求和 II
Easy  
给定一个初始元素全部为 0，大小为 m*n 的矩阵 M 以及在 M 上的一系列更新操作。

操作用二维数组表示，其中的每个操作用一个含有两个正整数 a 和 b 的数组表示，含义是将所有符合 0 <= i < a 以及 0 <= j < b 的元素 M[i][j] 的值都增加 1。

在执行给定的一系列操作后，你需要返回矩阵中含有最大整数的元素个数。

示例 1:

```

输入: 
m = 3, n = 3
operations = [[2,2],[3,3]]
输出: 4
解释: 
初始状态, M = 
[[0, 0, 0],
 [0, 0, 0],
 [0, 0, 0]]

执行完操作 [2,2] 后, M = 
[[1, 1, 0],
 [1, 1, 0],
 [0, 0, 0]]

执行完操作 [3,3] 后, M = 
[[2, 2, 1],
 [2, 2, 1],
 [1, 1, 1]]

M 中最大的整数是 2, 而且 M 中有4个值为2的元素。因此返回 4。

```

注意:

<ol>
	<li>m 和 n 的范围是 [1,40000]。</li>
	<li>a 的范围是 [1,m]，b 的范围是 [1,n]。</li>
	<li>操作数目不超过 10000。</li>
</ol>

### 题解:  
* 思路  
  找到数组重叠最多的部分，数组都是从左上角开始的矩型，只需要找到所有矩形中最短的边长，相乘可得解
* 代码  
```c++
	int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        // if (ops.size() == 0)
        // {
        //     return m*n;
        // }
        int i, j;
		i = m;
		j = n;
        // i = ops[0][0];
        // j = ops[0][1];
        for (auto op : ops)
        {
            if (i > op[0])
            {
                i = op[0];
            }
            if (j > op[1])
            {
                j = op[1];
            }
        }
        return i * j;
    }
```