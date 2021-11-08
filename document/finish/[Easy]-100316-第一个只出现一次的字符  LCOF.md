## 100316.第一个只出现一次的字符
Easy  
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例 1:

```

输入：s = "abaccdeff"
输出：'b'

```

示例 2:

```

输入：s = "" 
输出：' '

```

 

限制：

``0 <= s 的长度 <= 50000``

### 题解:  
* 思路  

* 代码  
```c++
    char firstUniqChar(string s)
    {
        vector<int> hogo(26);
        for (char i : s)
        {
            hogo[i - 'a']++;
        }
        for (char i : s)
        {
            if (hogo[i - 'a'] == 1)
            {
                return i;
            }
        }
        return ' ';
    }
```