## 89.格雷编码
``difficulty``:``Medium``  
<hr>
n 位格雷码序列 是一个由 ``2n`` 个整数组成的序列，其中：
<ul>
	<li>每个整数都在范围 ``[0, 2n - 1]`` 内（含 ``0`` 和 ``2n - 1``）</li> 限定范围
	<li>第一个整数是 ``0``</li>
	<li>一个整数在序列中出现 不超过一次</li>
	<li>每对 相邻 整数的二进制表示 恰好一位不同 ，且</li> 相邻差值为2的幂
	<li>第一个 和 最后一个 整数的二进制表示 恰好一位不同</li>
</ul>

给你一个整数 ``n`` ，返回任一有效的 n 位格雷码序列 。

 

示例 1：

```

输入：n = 2
输出：[0,1,3,2]
解释：
[0,1,3,2] 的二进制表示是 [00,01,11,10] 。
- 00 和 01 有一位不同
- 01 和 11 有一位不同
- 11 和 10 有一位不同
- 10 和 00 有一位不同
[0,2,3,1] 也是一个有效的格雷码序列，其二进制表示是 [00,10,11,01] 。
- 00 和 10 有一位不同
- 10 和 11 有一位不同
- 11 和 01 有一位不同
- 01 和 00 有一位不同

```

示例 2：

```

输入：n = 1
输出：[0,1]

```

 

提示：

<ul>
	<li>``1 <= n <= 16``</li>
</ul>

### 题解:  
* 思路  
根据规则可知  
	* 数组长度为2n-1,取值范围0～2n-1
	* 每个数只能出现一次
	* 相邻数做差为2的幂
	* 第一个数为0,最后一个数与第一个数的差为2的幂
  先确定最后一个数，最后一个数不能为1。之后的选择需要满足i与i-1,2n-1-i与2n-i符合规则。
* 官方题解
  `` ``
* 代码  
```c++
	vector<int> grayCode(int n) {
		
    }
```