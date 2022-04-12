## 100322.和为s的两个数字
``difficulty``:``Easy``  
<hr>
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。

 

示例 1：

```
输入：nums = [2,7,11,15], target = 9
输出：[2,7] 或者 [7,2]

```

示例 2：

```
输入：nums = [10,26,30,31,47,60], target = 40
输出：[10,30] 或者 [30,10]

```

 

限制：

<ul>
	<li>``1 <= nums.length <= 10^5``</li>
	<li>``1 <= nums[i] <= 10^6``</li>
</ul>

### 题解:  
* 思路  

* 代码  
```c++
	vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int,int> tmp;
        for(int i : nums){
            tmp[i]++;
        }
        cout<<endl;
        for(int i:nums){
            tmp[i]--;
            if(tmp[target-i]>0){
                return {i,target-i};
            }
            tmp[i]++;
        }
        return {};
    }
```