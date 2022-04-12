## 100328.翻转单词顺序
``difficulty``:``Easy``  
<hr>
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，则输出"student. a am I"。

 

示例 1：

```
输入: "the sky is blue"
输出: "blue is sky the"

```

示例 2：

```
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。

```

示例 3：

```
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。

```

 

说明：

<ul>
	<li>无空格字符构成一个单词。</li>
	<li>输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。</li>
	<li>如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。</li>
</ul>

注意：本题与主站 151 题相同：<a href="https://leetcode-cn.com/problems/reverse-words-in-a-string/">https://leetcode-cn.com/problems/reverse-words-in-a-string/</a>

注意：此题对比原题有改动

### 题解:  
* 思路  

* 代码  
```c++
	string reverseWords(string s)
    {
        vector<string> ret;
        string str = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (str != "")
                {
                    ret.push_back(str);
                    str = "";
                }
                continue;
            }
            str += s[i];
        }
        if (str[0] != ' ' && str != "")
        {
            ret.push_back(str);
        }
        if(ret.size()==0){
            return "";
        }
        str = ret[ret.size() - 1];
        for (int i = ret.size() - 2; i >= 0; i--)
        {
            cout << "\"" << ret[i] << "\""
                 << " ";
            str = str + " " + ret[i];
        }

        return str;
    }
```