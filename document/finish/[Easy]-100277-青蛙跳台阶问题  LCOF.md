## 100277.青蛙跳台阶问题
``difficulty``:``Easy``  
<hr>
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 ``n`` 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：

```
输入：n = 2
输出：2

```

示例 2：

```
输入：n = 7
输出：21

```

示例 3：

```
输入：n = 0
输出：1
```

提示：

<ul>
	<li>``0 <= n <= 100``</li>
</ul>

注意：本题与主站 70 题相同：<a href="https://leetcode-cn.com/problems/climbing-stairs/">https://leetcode-cn.com/problems/climbing-stairs/</a>

 

### 题解:  
* 思路  

* 代码  
```c++
	int numWays(int n) {
		if(n==0)
        {
            return 1;
        }

        vector<int> ret(n+1,0);
        int MOD=1000000007;
        ret[0]=1;
        ret[1]=1;
        for(int i=2;i<=n;i++){
            ret[i]=(ret[i-1]+ret[i-2])%MOD;
        }
        for(int i=0;i<=ret.size()-1;i++){
            cout<<"high:_"<<i<<"  ways:_ "<<ret[i]<<endl;
        }
        return ret[n];
    }
```