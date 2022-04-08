## 100327.礼物的最大价值
``difficulty``:``Medium``  
<hr>
在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

 

示例 1:

```
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1&rarr;3&rarr;5&rarr;2&rarr;1 可以拿到最多价值的礼物
```

 

提示：

<ul>
	<li>``0 < grid.length <= 200``</li>
	<li>``0 < grid[0].length <= 200``</li>
</ul>

### 题解:  
* 思路  
动态规划，二维数组映射为以为数组
* 代码  
```c++
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> ret((m+1)*(n+1),0);

        int ret_MAX=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               int pos=n*i+j+i+n+2;
               int pos_up=n*(i-1)+j+(i-1)+n+2;
               int pos_left=pos-1;
               ret[pos]=max(ret[pos_up]+grid[i][j],ret[pos_left]+grid[i][j]);
               ret_MAX=max(ret_MAX,ret[pos]);
            }
        }
        return ret_MAX;
    }
```