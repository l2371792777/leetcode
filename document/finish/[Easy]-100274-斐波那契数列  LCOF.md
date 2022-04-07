## 100274.斐波那契数列
``difficulty``:``Easy``  
<hr>
写一个函数，输入 ``n`` ，求斐波那契（Fibonacci）数列的第 ``n`` 项（即 ``F(N)``）。斐波那契数列的定义如下：

```

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```

斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

 

示例 1：

```

输入：n = 2
输出：1

```

示例 2：

```

输入：n = 5
输出：5

```

 

提示：

<ul>
	<li>``0 <= n <= 100``</li>
</ul>

### 题解:  
* 思路  

* 代码  
```c++
	int fib(int n) {
		vector<long> fibonacci(n+1);
        fibonacci[0]=0;
        fibonacci[1]=1;
        for(int i=2;i<=n;i++)
        {
            fibonacci[i]=(fibonacci[i-1]+fibonacci[i-2])%1000000007;
        }
        return fibonacci[n];
    }
	/**
     * 官方题解
     */
    int fib(int n) {
        if(n<2){
            return n;
        }
        int MOD=1000000007;
        int p,q,ret=1;
        for(int i=2;i<=n;i++){
            p=q;
            q=ret;
            ret=(p+q)%MOD;
        }
        return ret;
    }
```