// Leetcode 3.Longest Substring Without Repeating Characters
// Solution 1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string tempstring;
    int Len = 0, find = 0, position = 1;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        int exist = 0;
        for (int j = 0; j < find; j++)
        {
            if (s[i] == tempstring[j])
            {
                exist = 1;
                break;
            }
        }
        if (!exist)
        {
            tempstring += s[i];
            find++;
        }
        else
        {
            if (find > Len)
            {
                Len = find;
                tempstring.clear();
                find = 0;
                i = position;
                position++;
            }
            else
            {
                tempstring.clear();
                find = 0;
                i = position;
                position++;
            }
        }
        if (find > Len)
            Len = find;
    }
    cout << Len << endl;

    return 0;
}