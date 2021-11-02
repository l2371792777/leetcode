#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <cmath>
#include <stack>

using namespace std;

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

int main()
{
    MinStack solu;
    return 0;
}
