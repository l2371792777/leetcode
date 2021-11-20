## 594.最长和谐子序列
``difficulty``:``Easy``  
<hr>
和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 ``1`` 。

现在，给你一个整数数组 ``nums`` ，请你在所有可能的子序列中找到最长的和谐子序列的长度。

数组的子序列是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。

 

示例 1：

```

输入：nums = [1,3,2,2,5,2,3,7]
输出：5
解释：最长的和谐子序列是 [3,2,2,2,3]

```

示例 2：

```

输入：nums = [1,2,3,4]
输出：2

```

示例 3：

```

输入：nums = [1,1,1,1]
输出：0

```

 

提示：

<ul>
	<li>``1 <= nums.length <= 2 * 104``</li>
	<li>``-109 <= nums[i] <= 109``</li>
</ul>

### 题解:  
* 思路  
	* 统计数字出现个数，遍历数组找到相差为1出现次数最多的数字
	* 排序，滑动窗口
* 代码  
```c++
    int findLHS(vector<int> &nums)
    {
        map<int, int> res;
        for (int i : nums)
        {
            res[i]++;
        }
        int fmax = 0;
        int tmp = 0;
        for (int i : nums)
        {
            if (res[i + 1] == 0 && res[i - 1] == 0)
            {
                continue;
            }
            tmp = max(res[i] + res[i + 1], res[i] + res[i - 1]);
            if (tmp > fmax)
            {
                fmax = tmp;
            }
        }
        return fmax;
    }
```