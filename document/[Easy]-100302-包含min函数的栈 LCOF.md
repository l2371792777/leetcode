## 100302.包含min函数的栈
Easy  
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

 

示例:

```
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --&gt; 返回 -3.
minStack.pop();
minStack.top();      --&gt; 返回 0.
minStack.min();   --&gt; 返回 -2.

```

 

提示：

<ol>
	<li>各函数的调用总次数不超过 20000 次</li>
</ol>

 

注意：本题与主站 155 题相同：<a href="https://leetcode-cn.com/problems/min-stack/">https://leetcode-cn.com/problems/min-stack/</a>

### 题解:  
* 思路  
增加一个栈存储最小值序列
* 代码  
```  
class MinStack
{
    stack<int> res;
    stack<int> minlist;

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        res.push(x);
        if (minlist.empty())
        {
            minlist.push(x);
        }
        else if (x <= minlist.top())
        {
            minlist.push(x);
        }
    }

    void pop()
    {
        if (res.top() == minlist.top())
        {
            minlist.pop();
        }
        res.pop();
    }

    int top()
    {
        return res.top();
    }

    int min()
    {
        return minlist.top();
    }
};
```