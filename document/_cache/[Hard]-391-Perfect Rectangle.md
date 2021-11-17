## 391.完美矩形
``difficulty``:``Hard``  
<hr>
给你一个数组 ``rectangles`` ，其中 ``rectangles[i] = [x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub>]`` 表示一个坐标轴平行的矩形。这个矩形的左下顶点是 ``(x<sub>i</sub>, y<sub>i</sub>)`` ，右上顶点是 ``(a<sub>i</sub>, b<sub>i</sub>)`` 。

如果所有矩形一起精确覆盖了某个矩形区域，则返回 ``true`` ；否则，返回 ``false`` 。
 

示例 1：
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perectrec1-plane.jpg" style="width: 300px; height: 294px;" />
```

输入：rectangles = [[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]
输出：true
解释：5 个矩形一起可以精确地覆盖一个矩形区域。 

```

示例 2：
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perfectrec2-plane.jpg" style="width: 300px; height: 294px;" />
```

输入：rectangles = [[1,1,2,3],[1,3,2,4],[3,1,4,2],[3,2,4,4]]
输出：false
解释：两个矩形之间有间隔，无法覆盖成一个矩形。
```

示例 3：
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perfectrec3-plane.jpg" style="width: 300px; height: 294px;" />
```

输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[3,2,4,4]]
输出：false
解释：图形顶端留有空缺，无法覆盖成一个矩形。
```

示例 4：
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/27/perfecrrec4-plane.jpg" style="width: 300px; height: 294px;" />
```

输入：rectangles = [[1,1,3,3],[3,1,4,2],[1,3,2,4],[2,2,4,4]]
输出：false
解释：因为中间有相交区域，虽然形成了矩形，但不是精确覆盖。
```

 

提示：

<ul>
	<li>``1 <= rectangles.length <= 2 * 104``</li>
	<li>``rectangles[i].length == 4``</li>
	<li>``-105 <= x<sub>i</sub>, y<sub>i</sub>, a<sub>i</sub>, b<sub>i</sub> <= 105``</li>
</ul>

### 题解:  
* 思路  

* 代码  
```c++
class Solution
{
public:
    /**
     * 测试
     * @param
     */
    void test()
    {
    }

    /**
     * 判断是否覆盖
     */
    bool isCover(vector<vector<int>> pointmax, vector<vector<int>> pointmin, vector<int> rec)
    {
        auto itmax = pointmax.begin();
        auto itmin = pointmin.begin();
        for (itmax, itmin; itmax != pointmax.end(); itmax++, itmin++)
        {
            if ((rec[0] < (*itmax)[0] && rec[1] < (*itmax)[1]) && (rec[2] > (*itmin)[0] && rec[3] > (*itmin)[1]))
            {
                return false;
            }
        }
        return true;
    }
    /**
     * 题解
     * @param rectangles
     */
    bool isRectangleCover(vector<vector<int>> &rectangles)
    {
        int area = 0;
        vector<int> rec(4);
        vector<vector<int>> pointmax;
        vector<vector<int>> pointmin;
        for (auto it : rectangles)
        {
            //矩形总面积
            area = area + (it[2] - it[0]) * (it[3] - it[1]);
            //矩形边界
            rec[0] = min(rec[0], it[0]);
            rec[1] = min(rec[1], it[1]);
            rec[2] = max(rec[2], it[2]);
            rec[3] = max(rec[3], it[3]);
            //判断覆盖,若左下顶点小于已知右上顶点,并且右上顶点大于左下顶点，覆盖
            if (!isCover(pointmax, pointmin, it))
            {
                return false;
            }
            pointmax.push_back({it[2], it[3]});
            pointmax.push_back({it[0], it[1]});
        }
        //不存在覆盖面积相同
        int area_t = rec[0] * rec[1] * rec[2] * rec[3];
        if (area == area_t)
        {
            return true;
        }
        return false;
    }
};
```