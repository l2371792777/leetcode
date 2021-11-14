## 520.检测大写字母
Easy  
我们定义，在以下情况时，单词的大写用法是正确的：

<ul>
	<li>全部字母都是大写，比如 
```
"USA"
```
 。</li>
	<li>单词中所有字母都不是大写，比如 
```
"leetcode"
```
 。</li>
	<li>如果单词不只含有一个字母，只有首字母大写， 比如 
```
"Google"
```
 。</li>
</ul>

给你一个字符串 
```
word
```
 。如果大写用法正确，返回 
```
true
```
 ；否则，返回 
```
false
```
 。

 

示例 1：

```

输入：word = "USA"
输出：true

```

示例 2：

```

输入：word = "FlaG"
输出：false

```

 

提示：

<ul>
	<li>1 <= word.length <= 100</li>
	<li>word
```
 由小写和大写英文字母组成</li>
</ul>

### 题解:  
* 思路  
调用islower(),isupper()判断大小写  
首字母大写，后面字符全为大写或全为小写，  
首字母小写，后面字符全为小写
* 代码  
```c++
	bool detectCapitalUse(string word)
    {
        if (word.size() == 1)
        {
            return true;
        }
        bool sign = true;
        bool hogo = true;
        if (word[0] >= 'A' && word[0] <= 'Z')
        {
            sign = false;
        }
        else
        {
            sign = true;
        }
        if (word[1] >= 'A' && word[1] <= 'Z')
        {
            hogo = false;
        }
        else
        {
            hogo = true;
        }
        if (sign && !hogo)
        {
            return false;
        }
        for (int i = 1; i < word.size(); i++)
        {
            if (hogo && (word[i] >= 'A' && word[i] <= 'Z'))
            {
                return false;
            }
            else if (!hogo && (word[i] >= 'a' && word[i] <= 'z'))
            {
                return false;
            }
        }
        return true;
    }
```