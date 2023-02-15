// UVA 939 Genes
#include <bits/stdc++.h>
using namespace std;
// DD = D DR = D DN = R
// RR = R RN = N NN = N
int main()
{
    int n, find = 0;
    string name, gene;
    string exist[100], found[100];
    string test[2];
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> gene;
        //判斷已知基因的人
        if (gene == "dominant" or gene == "recessive" or gene == "non-existent")
        {
            exist[find] = name;
            found[find] = gene;
            find++;
        }
        //判斷小孩
        else
        {
            for (int i = 0; i < find; i++)
            {
                if (name == exist[i])
                {
                    test[count] = found[i];
                    count++;
                }
            }
            if (count == 2)
            {
                if ((test[0] == "dominant" and test[1] == "dominant") or (test[0] == "dominant" and test[1] == "recessive") or (test[0] == "recessive" and test[1] == "dominant"))
                {
                    exist[find] = gene;
                    found[find] = "dominant";
                    find++;
                }
                else if ((test[0] == "dominant" and test[1] == "non-existent") or (test[0] == "non-existent" and test[1] == "dominant") or (test[0] == "recessive" and test[1] == "recessive"))
                {
                    exist[find] = gene;
                    found[find] = "recessive";
                    find++;
                }
                else
                {
                    exist[find] = gene;
                    found[find] = "non-existent";
                    find++;
                }
                count = 0;
            }
        }
    }
    for (int i = 0; i < find; i++)
    {
        for (int j = i + 1; j < find; j++)
        {
            if (exist[j] < exist[i])
            {
                swap(exist[j], exist[i]);
                swap(found[j], found[i]);
            }
        }
    }
    for (int i = 0; i < find; i++)
    {
        cout << exist[i] << " " << found[i] << endl;
    }

    return 0;
}