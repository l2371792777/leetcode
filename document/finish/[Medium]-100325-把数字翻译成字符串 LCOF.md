## 100325.把数字翻译成字符串
``difficulty``:``Medium``  
<hr>
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 &ldquo;a&rdquo; ，1 翻译成 &ldquo;b&rdquo;，&hellip;&hellip;，11 翻译成 &ldquo;l&rdquo;，&hellip;&hellip;，25 翻译成 &ldquo;z&rdquo;。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

```
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
```

 

提示：

<ul>
	<li>``0 <= num < 231``</li>
</ul>

### 题解:  
* 思路  

* 代码  
```c++
	/**
     * 题解
     * @param
     */
    int translateNum(int num) {
        string nums=to_string(num);
        int n=nums.size();
        vector<int> ret(n+1,0);
        ret[0]=ret[1]=1;
        for(int i=1;i<n;i++){
            ret[i+1]+=ret[i];
            cout<<" i_"<<i<<" nums_"<<nums[i];
            int tmp=int(nums[i-1]-'0')*10+int(nums[i]-'0');
            cout<<" tmp_"<<tmp;
            if(tmp>=0&&tmp<=25&&nums[i-1]!='0'){
                ret[i+1]+=ret[i-1];
            }
            cout<<" ret[i+1]_"<<ret[i+1]<<endl;
        }
        return ret[n];
    }
```