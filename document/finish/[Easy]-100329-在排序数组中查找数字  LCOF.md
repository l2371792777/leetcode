## 100329.在排序数组中查找数字 I
Easy  
统计一个数字在排序数组中出现的次数。

 

示例 1:

```

输入: nums = [5,7,7,8,8,10], target = 8
输出: 2
```

示例 2:

```

输入: nums = [5,7,7,8,8,10], target = 6
输出: 0
```

 

提示：

<ul>
	<li>``0 <= nums.length <= 105``</li>
	<li>``-109 <= nums[i] <= 109``</li>
	<li>``nums`` 是一个非递减数组</li>
	<li>``-109 <= target <= 109``</li>
</ul>

 

注意：本题与主站 34 题相同（仅返回值不同）：<a href="https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/">https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/</a>

### 题解:  
* 思路  
	* 二分搜索找到目标数字，向两侧搜索出现次数，  
  	  特殊情况，数组为空，数组个数为1  
	* 遍历数组
* 代码  
```c++
	int count = 0;
        for (int i : nums)
        {
            if (i == target)
            {
                count++;
            }
        }

        return count;
```