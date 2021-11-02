## 100273.用两个栈实现队列
Easy  
用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 ``appendTail`` 和 ``deleteHead`` ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，``deleteHead`` 操作返回 -1 )

 

示例 1：

```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

```

示例 2：

```
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]

```

提示：

<ul>
	<li>``1 &lt;= values &lt;= 10000``</li>
	<li>``最多会对 appendTail、deleteHead 进行 10000 次调用``</li>
</ul>

### 题解:  
* 思路  
	建立两个栈 add,del  
	栈为倒序存放数据，存入add后在转存到del即为正序  
	向队尾添加元素==>向add压入元素  
	删除头部元素==>弹出del元素  
* 代码  
```  
class CQueue
{
    stack<int> add;
    stack<int> del;

public:
    void test()
    {
    }
    CQueue()
    {
    }

    void appendTail(int value)
    {
        add.push(value);
    }

    int deleteHead()
    {
        if (add.empty() && del.empty())
        {
            return -1;
        }
        if(del.empty())
        {
            while (!add.empty())
            {
                del.push(add.top());
                add.pop();
            }
        }

        int res = del.top();
        del.pop();
        return res;
    }
};
```