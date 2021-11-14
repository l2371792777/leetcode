## 677.键值映射
Medium  
实现一个 
``MapSum``类，支持两个方法，``insert``和``sum``：

<ul>
	<li>``MapSum()``初始化 ``MapSum``对象</li>
	<li>``void insert(String key, int val)``插入 ``key-val``键值对，字符串表示键 ``key``，整数表示值 ``val``。如果键 ``key``已经存在，那么原来的键值对将被替代成新的键值对。</li><li>``int sum(string prefix)``返回所有以该前缀 ``prefix``开头的键 ``key``的值的总和。</li></ul>

 

示例：

```

输入：
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
输出：
[null, null, 3, null, 5]

解释：
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);  
mapSum.sum("ap");           // return 3 (apple = 3)
mapSum.insert("app", 2);    
mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)

```

 

提示：

<ul>
	<li>1 <= key.length, prefix.length <= 50</li>
	<li>key
```
 和 
```
prefix
```
 仅由小写英文字母组成</li>
	<li>1 <= val <= 1000</li>
	<li>最多调用 
```
50
```
 次 
```
insert
```
 和 
```
sum</li>
</ul>

### 题解:  
* 思路  
	没存入一个键值对，存储他的前缀值
	有重复的键值对存入，删除当前键值对前缀值
* 代码  
```c++
class MapSum
{
    map<string, int> sums;
    map<string, int> cur;

public:
    void test()
    {
    }
    MapSum()
    {
    }

    void insert(string key, int val)
    {
        string tmp = "";
        if (cur.find(key) != cur.end())
        {
            //若已存在，删除当前存储值
            for (auto i : key)
            {
                tmp += i;
                sums[tmp] -= cur[key];
            }
        }
        cur[key]=val;
        tmp = "";
        for (auto i : key)
        {
            tmp += i;
            sums[tmp] += val;
        }
    }

    int sum(string prefix)
    {
        return sums[prefix];
    }
};

```