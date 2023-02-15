// Solution 2
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    bool str[128] = {0};
    int count = 0, ans = 0, position = 0;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
    {
        if (!str[s[i]])
        {
            count++;
            str[s[i]] = 1;
        }
        else
        {
            if (count > ans)
                ans = count;
            count = 0;
            i = position++;
            for (int i = 0; i < 128; i++)
                str[i] = 0;
        }
    }
    if (count > ans)
        ans = count;
    cout << ans;
    
    return 0;
}