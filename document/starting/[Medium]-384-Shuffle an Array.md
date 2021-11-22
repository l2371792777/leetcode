## 384.打乱数组
``difficulty``:``Medium``  
<hr>
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。

实现 ``Solution`` class:

<ul>
	<li>``Solution(int[] nums)`` 使用整数数组 ``nums`` 初始化对象</li>
	<li>``int[] reset()`` 重设数组到它的初始状态并返回</li>
	<li>``int[] shuffle()`` 返回数组随机打乱后的结果</li>
</ul>

 

示例：

```

输入
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
输出
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2]

```

 

提示：

<ul>
	<li>``1 <= nums.length <= 200``</li>
	<li>``-106 <= nums[i] <= 106``</li>
	<li>``nums`` 中的所有元素都是 唯一的</li>
	<li>最多可以调用 ``5 * 104`` 次 ``reset`` 和 ``shuffle``</li>
</ul>

### 题解:  
* 思路  
从源数组随机取一个数，插入待返回数组，输出插入的数；  
优化:将随机选取的数和最后一个数交换，删除最后一个数
* 代码  
```c++
    vector<int> cur;

public:
    /**
     * 测试
     * @param
     */
    void test()
    {
        vector<int> test = reset();
        for (auto i : test)
        {
            cout << i << " ";
        }
        cout << endl;
        test=shuffle();
        for (auto i : test)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    /**
     * 题解
     * @param nums 无重复数组
     */
    Solution(vector<int> &nums)
    {
        cur = nums;
    }

    vector<int> reset()
    {
        return cur;
    }

    vector<int> shuffle()
    {
        vector<int> tmp = cur;
        vector<int> res;
        int n, i;
        while (!tmp.empty())
        {
            n = tmp.size();
            i = rand() % n;
            res.push_back(tmp[i]);
            tmp.erase(tmp.begin() + i);
        }
        return res;
    }
```