## 367.有效的完全平方数
Easy  
给定一个 正整数 ``num`` ，编写一个函数，如果 ``num`` 是一个完全平方数，则返回 ``true`` ，否则返回 ``false`` 。

进阶：不要 使用任何内置的库函数，如  ``sqrt`` 。

 

示例 1：

```

输入：num = 16
输出：true

```

示例 2：

```

输入：num = 14
输出：false

```

 

提示：

<ul>
	<li>``1 <= num <= 2^31 - 1``</li>
</ul>

### 题解:  
* 思路  

* 代码  
```  
	bool isPerfectSquare(int num)
    {
        long temp = num;
        long i = 0;
        for (; i * i < temp; i++)
        {
        }
        if (i * i == temp)
        {
            return true;
        }
        return false;
    }
```