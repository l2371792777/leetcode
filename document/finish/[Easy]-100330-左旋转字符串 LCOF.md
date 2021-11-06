## 100330.左旋转字符串
Easy  
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

 

示例 1：

```
输入: s = "abcdefg", k = 2
输出: "cdefgab"

```

示例 2：

```
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"

```

 

限制：

<ul>
	<li>``1 <= k < s.length <= 10000``</li>
</ul>

### 题解:  
* 思路  
分割两部分字符串，重新组合  
* 代码  
```c++
class Solution
{
public:
    void test()
	{
        string cur = "We are happy.";
        cout<<reverseLeftWords(cur,4);
    }
    string reverseLeftWords(string s, int n)
    {
        //string cur;
        // for (int i = n; i < s.size(); i++)
        // {
        //     cur += s[i];
        // }
        // for (int i = 0; i < n; i++)
        // {
        //     cur += s[i];
        // }
        // return cur;
        return s.substr(n)+s.substr(0,n);
    }
};

```