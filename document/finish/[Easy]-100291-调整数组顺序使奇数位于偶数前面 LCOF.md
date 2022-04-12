## 100291.调整数组顺序使奇数位于偶数前面
``difficulty``:``Easy``  
<hr>
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。

 

示例：

```

输入：nums = [1,2,3,4]
输出：[1,3,2,4] 
注：[3,1,2,4] 也是正确的答案之一。
```

 

提示：

<ol>
	<li>``0 <= nums.length <= 50000``</li>
	<li>``0 <= nums[i] <= 10000``</li>
</ol>

### 题解:  
* 思路  

* 代码  
```c++
	vector<int> exchange(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            while(nums[i]%2!=0&&i<j){
                i++;
            }
            while(nums[j]%2==0&&i<j){
                j--;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        return nums;
    }
```