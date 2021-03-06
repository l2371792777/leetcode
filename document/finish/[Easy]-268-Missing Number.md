## 268.丢失的数字
Easy  
给定一个包含 ``[0, n]`` 中 ``n`` 个数的数组 ``nums`` ，找出 ``[0, n]`` 这个范围内没有出现在数组中的那个数。

<ul>
</ul>

 

示例 1：

```

输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
```

示例 2：

```

输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
```

示例 3：

```

输入：nums = [9,6,4,2,3,5,7,0,1]
输出：8
解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
```

示例 4：

```

输入：nums = [0]
输出：1
解释：n = 1，因为有 1 个数字，所以所有的数字都在范围 [0,1] 内。1 是丢失的数字，因为它没有出现在 nums 中。
```

 

提示：

<ul>
	<li>``n == nums.length``</li>
	<li>``1 <= n <= 104``</li>
	<li>``0 <= nums[i] <= n``</li>
	<li>``nums`` 中的所有数字都 独一无二</li>
</ul>

 

进阶：你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?

### 题解:  
* 思路  
所有的数都在[0-n]范围内，计算0-n的和，与给定数组相减，得到的值即为缺失的数
* 代码  
```c++
	int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += i;
        }
        for (int i : nums)
        {
            sum -= i;
        }
        return sum;
    }
```