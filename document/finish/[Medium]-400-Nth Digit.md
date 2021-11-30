## 400.第 N 位数字
``difficulty``:``Medium``  
<hr>
给你一个整数 ``n`` ，请你在无限的整数序列 ``[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...]`` 中找出并返回第 ``n`` 位数字。

 

示例 1：

```

输入：n = 3
输出：3

```

示例 2：

```

输入：n = 11
输出：0
解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。

```

 

提示：

<ul>
	<li>``1 <= n <= 231 - 1``</li>
</ul>

### 题解:  
* 思路  
参考leet官方题解
* 代码  
```c++
/**
     * 题解
     * @param
     */
    int findNthDigit(int n)
    {
        int pos = 1; //判断位数
        long long digits = 9;
        long long num = 0; //每位占据数字个数
        while (n)
        {
            num = pos * digits;
            cout << num << endl;
            if (n <= num)
            {
                break;
            }
            pos++;
            digits *= 10;
            n = n - num;
        }
        //第几个数字
        int offset = (n - 1) / pos;
        cout <<"offset... "<< offset << endl;
        //获取位数最小数字
        int beginDigit = 1;
        for (int i = 0; i < pos - 1; i++)
        {
            beginDigit *= 10;
        }
        //数字内位数
        int mod = (n - 1) % pos;
        cout <<"mod... "<< mod << endl;
        string resDigit = to_string(beginDigit + offset);
        cout <<"resDigit... "<< resDigit << endl;
        return resDigit[mod] - '0';
    }
```