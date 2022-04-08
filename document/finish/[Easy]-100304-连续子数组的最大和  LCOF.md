## 100304.连续子数组的最大和
``difficulty``:``Easy``  
<hr>
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。

要求时间复杂度为O(n)。

 

示例1:

```
输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
```

 

提示：

<ul>
	<li>``1 <= arr.length <= 10^5``</li>
	<li>``-100 <= arr[i] <= 100``</li>
</ul>

注意：本题与主站 53 题相同：<a href="https://leetcode-cn.com/problems/maximum-subarray/">https://leetcode-cn.com/problems/maximum-subarray/</a>

 

### 题解:  
* 思路  

* 代码  
```c++
	int maxSubArray(vector<int>& nums) {
		int n=nums.size()-1;
        int ret_MAX;
        vector<int> ret(n+1);
        ret_MAX=ret[0]=nums[0];
        for(int i=1;i<=n;i++){
            ret[i]=max(nums[i],nums[i]+ret[i-1]);
            ret_MAX=max(ret_MAX,ret[i]);
        }
        return ret_MAX;
    }
```