//...leetcode_211_2021-10-19
//...https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <string>
#include <map>
#include <set>

using namespace std;

void test();

class WordDictionary
{
public:
    map<int, set<string>> index;
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        int n = word.size();
        if (index.find(n) != index.end())
        {
            index[n].insert(word);
        }
        else
        {
            set<string> temp;
            temp.insert(word);
            index[n] = temp;
        }
    }

    bool search(string word)
    {
        int n = word.size();
        bool sign = false;
        if (index[n].count(word) > 0)
        {
            sign = true;
            return sign;
        }

        string temp = "";
        for (auto it = index[n].begin(); it != index[n].end(); it++)
        {
            temp = *it;
            sign = true;
            for (int i = 0; i < n; i++)
            {
                if (word[i] != '.' && temp[i] != word[i])
                {
                    sign = false;
                    continue;
                }
            }
            if (sign)
            {
                index[n].insert(word);
                return sign;
            }
        }

        return sign;
    }
};

int main()
{
    test();
    return 0;
}

void test()
{
}