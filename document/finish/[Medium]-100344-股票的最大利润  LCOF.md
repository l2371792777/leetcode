## 100344.股票的最大利润
``difficulty``:``Medium``  
<hr>
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

 

示例 1:

```
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。

```

示例 2:

```
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
```

 

限制：

``0 <= 数组长度 <= 10^5``

 

注意：本题与主站 121 题相同：<a href="https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/">https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/</a>

### 题解:  
* 思路  

* 代码  
```c++
     int maxProfit(vector<int>& prices) {
        int size=prices.size()-1;
        int ret_Max=0;
        int ret_Min=0;
        int Max=prices[size];
        int Min=Max;
        for(int i=size-1;i>=0;i--){
            if(prices[i]>Max){
                Max=prices[i];
                Min=Max;
            }
            else if(prices[i]<Min){
                Min=prices[i];
                if((Max-Min)>(ret_Max-ret_Min)){
                     ret_Max=Max;
                     ret_Min=Min;
                }
            }
        }
        return ret_Max-ret_Min;
    }
```