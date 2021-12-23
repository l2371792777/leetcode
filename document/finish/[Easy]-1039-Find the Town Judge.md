## 1039.找到小镇的法官
``difficulty``:``Easy``  
<hr>
小镇里有 ``n`` 个人，按从 ``1`` 到 ``n`` 的顺序编号。传言称，这些人中有一个暗地里是小镇法官。

如果小镇法官真的存在，那么：

<ol>
	<li>小镇法官不会信任任何人。</li>
	<li>每个人（除了小镇法官）都信任这位小镇法官。</li>
	<li>只有一个人同时满足属性 1 和属性 2 。</li>
</ol>

给你一个数组 ``trust`` ，其中 ``trust[i] = [a<sub>i</sub>, b<sub>i</sub>]`` 表示编号为 ``a<sub>i</sub>`` 的人信任编号为 ``b<sub>i</sub>`` 的人。

如果小镇法官存在并且可以确定他的身份，请返回该法官的编号；否则，返回 ``-1`` 。

 

示例 1：

```

输入：n = 2, trust = [[1,2]]
输出：2

```

示例 2：

```

输入：n = 3, trust = [[1,3],[2,3]]
输出：3

```

示例 3：

```

输入：n = 3, trust = [[1,3],[2,3],[3,1]]
输出：-1

```
 

提示：

<ul>
	<li>``1 <= n <= 1000``</li>
	<li>``0 <= trust.length <= 104``</li>
	<li>``trust[i].length == 2``</li>
	<li>``trust`` 中的所有``trust[i] = [a<sub>i</sub>, b<sub>i</sub>]`` 互不相同</li>
	<li>``a<sub>i</sub> != b<sub>i</sub>``</li>
	<li>``1 <= a<sub>i</sub>, b<sub>i</sub> <= n``</li>
</ul>

### 题解:  
* 思路  
只有满足两个条件的人才是法官  
	* 不相信别人
	* 每个人都相信他
* 代码  
```c++
	int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> pers(n);
        vector<bool> sign(n);
        for(auto it : trust)
        {
            pers[it[1]-1]++;
            sign[it[0]-1]=true;
            if(pers[it[1]-1]==n-1&&!sign[it[0]-1])
            {
                return it[1];
            }
        }
        for(int i=0;i<n;i++)
        {
            if(pers[i]==n-1&&!sign[i])
            {
                return i+1;
            }
        }
        return -1;
    }
```