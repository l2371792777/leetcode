## 299.猜数字游戏
Medium  
你在和朋友一起玩 <a href="https://baike.baidu.com/item/%E7%8C%9C%E6%95%B0%E5%AD%97/83200?fromtitle=Bulls+and+Cows&amp;fromid=12003488&amp;fr=aladdin" target="_blank">猜数字（Bulls and Cows）</a>游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：

<ul>
	<li>猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls", 公牛），</li>
	<li>有多少位属于数字猜对了但是位置不对（称为 "Cows", 奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。</li>
</ul>

给你一个秘密数字 ``secret`` 和朋友猜测的数字 ``guess`` ，请你返回对朋友这次猜测的提示。

提示的格式为 ``"xAyB"`` ，``x`` 是公牛个数， ``y`` 是奶牛个数，``A`` 表示公牛，``B`` 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。

 

示例 1:

```

输入: secret = "1807", guess = "7810"
输出: "1A3B"
解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1807"
  |
"7810"
```

示例 2:

```

输入: secret = "1123", guess = "0111"
输出: "1A1B"
解释: 数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
"1123"        "1123"
  |      or     |
"0111"        "0111"
注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
```

示例 3：

```

输入：secret = "1", guess = "0"
输出："0A0B"

```

示例 4：

```

输入：secret = "1", guess = "1"
输出："1A0B"

```

 

提示：

<ul>
	<li>``1 <= secret.length, guess.length <= 1000``</li>
	<li>``secret.length == guess.length``</li>
	<li>``secret`` 和 ``guess`` 仅由数字组成</li>
</ul>

### 题解:  
* 思路  

* 代码  
```c++
	string getHint(string secret, string guess)
    {
        map<char, int> hogo;
        map<char, int> hogs;
        for (int i = 0; i < secret.size(); i++)
        {
            hogo[secret[i]]++;
            hogs[guess[i]]++;
        }
        int A = 0, B = 0;
        for (int i = 0; i < secret.size(); i++)
        {
            if (secret[i] == guess[i])
            {
                A++;
                hogo[secret[i]]--;
                hogs[secret[i]]--;
            }
			else if (hogo[guess[i]] != 0 && hogs[guess[i]] != 0)
            {
                B++;
                hogo[guess[i]]--;
                hogs[guess[i]]--;
            }
        }

        return to_string(A) + 'A' + to_string(B) + 'B';
    }
```