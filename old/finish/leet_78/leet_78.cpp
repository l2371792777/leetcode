#include <iostream>
#include <vector>

using namespace std;

void test(vector<vector<int>> &matrix);
int main(int argc, char *argv[])
{
    vector<vector<int>> hogo = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 0}, {0, 1, 1, 1}};
    test(hogo);
    return 0;
}

void test(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> mpos(m, 1);
    vector<int> npos(n, 1);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                mpos[i] = 0;
                npos[j] = 0;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mpos[i] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (npos[i] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[j][i] = 0;
            }
        }
    }
}