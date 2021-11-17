## 318.最大单词长度乘积
``difficulty``:``Medium``  
<hr>
给定一个字符串数组 ``words``，找到 ``length(word[i]) * length(word[j])`` 的最大值，并且这两个单词不含有公共字母。你可以认为每个单词只包含小写字母。如果不存在这样的两个单词，返回 0。

 

示例 1:

```

输入: ["abcw","baz","foo","bar","xtfn","abcdef"]
输出: 16 
解释: 这两个单词为 "abcw", "xtfn"。
```

示例 2:

```

输入: ["a","ab","abc","d","cd","bcd","abcd"]
输出: 4 
解释: 这两个单词为 "ab", "cd"。
```

示例 3:

```

输入: ["a","aa","aaa","aaaa"]
输出: 0 
解释: 不存在这样的两个单词。

```

 

提示：

<ul>
	<li>``2 <= words.length <= 1000``</li>
	<li>``1 <= words[i].length <= 1000``</li>
	<li>``words[i]`` 仅包含小写字母</li>
</ul>

### 题解:  
* 思路  
	* 题目分为两部分，找乘积最长的组合,时间复杂度为``n*n-1``  
	另一部分是判断是否有重复单词，我选择的是将单词存入set分别进行一次遍历确认是否重复,时间复杂度太高超时  
	* 题解采用位运算方式判断重复问题,  
	用数字的低26位表示字母，两字母的数字表示进行与运算，若不为0，则有重复字母

* 代码  
官方题解：
```c++
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int length = words.size();
        vector<int> masks(length);
        for (int i = 0; i < length; i++) {
            string word = words[i];
            int wordLength = word.size();
            for (int j = 0; j < wordLength; j++) {
                masks[i] |= 1 << (word[j] - 'a');
            }
        }
        int maxProd = 0;
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if ((masks[i] & masks[j]) == 0) {
                    maxProd = max(maxProd, int(words[i].size() * words[j].size()));
                }
            }
        }
        return maxProd;
    }

};
```
我的题解：
```c++
/**
     * 判断是否有重复字母
     * @param word1
     * @param word2
     * return
     */
    bool isHasEqual(string word1, string word2)
    {
        set<char> cur1;
        set<char> cur2;
        for (auto i : word1)
        {
            cur1.insert(i);
        }
        for (auto i : word2)
        {
            if (cur1.find(i) != cur1.end())
            {
                return true;
            }
            cur2.insert(i);
        }
        for (auto i : word1)
        {
            if (cur2.find(i) != cur2.end())
            {
                return true;
            }
        }
        return false;
    }

    /**
     * 题解
     * @param
     */
    int maxProduct(vector<string> &words)
    {
        int lengthmax = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                int mul = words[i].size() * words[j].size();
                if (mul > lengthmax && !isHasEqual(words[i], words[j]))
                {
                    lengthmax = mul;
                }
            }
        }
        return lengthmax;
    }
```