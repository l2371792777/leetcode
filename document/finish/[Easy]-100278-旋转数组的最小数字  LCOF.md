## 100278.旋转数组的最小数字
Easy  
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 ``[3,4,5,1,2]`` 为 ``[1,2,3,4,5]`` 的一个旋转，该数组的最小值为1。  

示例 1：

```
输入：[3,4,5,1,2]
输出：1

```

示例 2：

```
输入：[2,2,2,0,1]
输出：0

```

注意：本题与主站 154 题相同：<a href="https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/">https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/</a>

### 题解:  
* 思路  
遍历，分界点
* 代码  
```c++
    int minArray(vector<int>& numbers) {
        int n = numbers.size() - 1;
        for (int i = 0; i < n; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                return numbers[i + 1];
            }
        }
        return numbers[0];
    }
```