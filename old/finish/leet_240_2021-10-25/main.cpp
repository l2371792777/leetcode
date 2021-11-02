//...leetcode_240_2021-10-25
//...https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>

using namespace std;

class MinStack
{
public:
    void test()
    {
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = n - 1, line = 0;
        while (row > -1 && line < m)
        {
            cout << matrix[line][row] << " " << line << " " << row;
            if (target == matrix[line][row])
            {
                return true;
            }
            if (target > matrix[line][row])
            {
                line++;
            }
            else
            {
                row--;
            }
        }
        return false;
    }
};

int main()
{
    MinStack solu;
    solu.test();
    return 0;
}
