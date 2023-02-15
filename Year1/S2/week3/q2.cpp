// Game(1)
#include <bits/stdc++.h>
using namespace std;
class Player
{
public:
    Player() {}
    Player(int num, string name)
    {
        if (num < 0 or num > 5)
            cerr << "out of range" << endl;
        else if (name.size() >= 20)
            cerr << "your name is illegal" << endl;
        else if (name.size() < 20)
        {
            for (int i = 0; i < name.size(); i++)
            {
                if (isdigit(name[i]))
                {
                    cerr << "your name is illegal" << endl;
                    break;
                }
            }
        }
    }
    int getPlayerNum()
    {
        return number;
    }
    string getPlayerName()
    {
        return name;
    }
    bool setPlayerNum(int n)
    {
        number = n;
        if (number < 0 or number > 5)
            return false;
        else
            return true;
    }
    bool setPlayerName(string n)
    {
        name = n;
        int x = 0;
        if (name.size() >= 20)
            return false;
        for (int i = 0; i < name.size(); i++)
        {
            if (isdigit(name[i]))
            {
                x = 1;
                break;
            }
        }
        if (x)
            return false;
        return true;
    }

private:
    int number;
    string name;
};