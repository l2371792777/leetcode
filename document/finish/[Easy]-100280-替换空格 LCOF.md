## 100280.替换空格
Easy  
请实现一个函数，把字符串 ``s`` 中的每个空格替换成"%20"。

 

示例 1：

```
输入：s = "We are happy."
输出："We%20are%20happy."
```

 

限制：

``0 <= s 的长度 <= 10000``

### 题解:  
* 思路  
1.找到空格位置，替换元字符串内空格  
2.拷贝原字符串，遇到空格替换
* 代码  
```c++
class Solution
{
public:
    void test()
    {
        
    }
    string replaceSpace(string s) {
        string res;
        for (char cur : s)
        {
            if (cur != ' ')
            {
                res += cur;
            }
            else
            {
                res += "%20";
            }
        }
        return res;
    }
};
```