## 1330.最长定差子序列
Medium  
给你一个整数数组 ``arr`` 和一个整数 ``difference``，请你找出并返回 ``arr`` 中最长等差子序列的长度，该子序列中相邻元素之间的差等于 ``difference`` 。

子序列 是指在不改变其余元素顺序的情况下，通过删除一些元素或不删除任何元素而从 ``arr`` 派生出来的序列。

 

示例 1：

```

输入：arr = [1,2,3,4], difference = 1
输出：4
解释：最长的等差子序列是 [1,2,3,4]。
```

示例 2：

```

输入：arr = [1,3,5,7], difference = 1
输出：1
解释：最长的等差子序列是任意单个元素。

```

示例 3：

```

输入：arr = [1,5,7,8,5,3,4,2,1], difference = -2
输出：4
解释：最长的等差子序列是 [7,5,3,1]。

```

 

提示：

<ul>
	<li>``1 <= arr.length <= 105``</li>
	<li>``-104 <= arr[i], difference <= 104``</li>
</ul>

### 题解:  
* 思路  
	动态规划  
	后面的解依赖前面的解,要求得arr[i]的最长子序列，需要先求得arr[i-diffrernce],在这基础上+1
* 代码  
```c++
    int longestSubsequence(vector<int> &arr, int difference)
    {
        map<int, int> hogo;
        int max=0;
        for (int i : arr)
        {
            hogo[i] = hogo[i - difference] + 1;
            if(hogo[i]>max)
            {
                max=hogo[i];
            }
        }
        return max;
    }
```