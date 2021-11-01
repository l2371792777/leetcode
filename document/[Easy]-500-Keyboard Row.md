# 500.键盘行
Easy  
给你一个字符串数组 ``words`` ，只返回可以使用在 美式键盘 同一行的字母打印出来的单词。键盘如下图所示。

美式键盘 中：

<ul>
	<li>第一行由字符 ``"qwertyuiop"`` 组成。</li>
	<li>第二行由字符 ``"asdfghjkl"`` 组成。</li>
	<li>第三行由字符 ``"zxcvbnm"`` 组成。</li>
</ul>

<img alt="American keyboard" src="https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2018/10/12/keyboard.png" style="width: 100%; max-width: 600px" />

 

示例 1：

```

输入：words = ["Hello","Alaska","Dad","Peace"]
输出：["Alaska","Dad"]
```

示例 2：

```

输入：words = ["omk"]
输出：[]
```

示例 3：

```

输入：words = ["adsdf","sfd"]
输出：["adsdf","sfd"]
```

 

提示：

<ul>
	<li>``1 <= words.length <= 20``</li>
	<li>``1 <= words[i].length <= 100``</li>
	<li>``words[i]`` 由英文字母（小写和大写字母）组成</li>
</ul>

### 题解:  
* 思路  
  确定一个字母所属字符串，找出和它不在一个字符串的字母

* 代码
```  
vector<string> findWords(vector<string> &words)
    {
        vector<string> res;
        vector<string> key = {"", "qwertyuiopQWERTYUIOP", "asdfghjklASDFGHJJKL", "zxcvbnmZXCVBNM"};

        for (string i : words)
        {
            int sign = 0;
            bool pos = true;
            if (key[1].find(i[0]) != key[1].npos)
            {
                sign = 1;
            }
            else if (key[2].find(i[0]) != key[2].npos)
            {
                sign = 2;
            }
            else if (key[3].find(i[0]) != key[3].npos)
            {
                sign = 3;
            }

            for (char j : i)
            {
                if (key[sign].find(j) == key[sign].npos)
                {
                    pos = false;
                }
            }
            if (pos)
            {
                res.push_back(i);
            }
        }
        return res;
    }
```