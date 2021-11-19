## 397.整数替换
``difficulty``:``Medium``  
<hr>
给定一个正整数 ``n`` ，你可以做如下操作：

<ol>
	<li>如果 ``n`` 是偶数，则用 ``n / 2``替换 ``n`` 。</li>
	<li>如果 ``n`` 是奇数，则可以用 ``n + 1``或``n - 1``替换 ``n`` 。</li>
</ol>

``n`` 变为 ``1`` 所需的最小替换次数是多少？

 

示例 1：

```

输入：n = 8
输出：3
解释：8 -> 4 -> 2 -> 1

```

示例 2：

```

输入：n = 7
输出：4
解释：7 -> 8 -> 4 -> 2 -> 1
或 7 -> 6 -> 3 -> 2 -> 1

```

示例 3：

```

输入：n = 4
输出：2

```

 

提示：

<ul>
	<li>``1 <= n <= 231 - 1``</li>
</ul>

### 题解:  
* 思路  
	* 动态规划（遍历0-n,超时）
		* i为偶数时,``dp[i]=dp[i/2]+1``
		* i为奇书时,``dp[i]=min(dp[i/2],dp[i/2+1])+2``
	* 递归，逻辑和动态规划相同
* 代码  
```c++
    /**
     * 题解
     * @param
     */
    int integerReplacement(int n)
    {
        if (n == 1)
        {
            return 0;
        }
        if (n % 2 == 0)
        {
            return 1 + integerReplacement(n / 2);
        }
        else
        {
            return 2 + min(integerReplacement(n / 2), integerReplacement(n / 2 + 1));
        }
    }
```