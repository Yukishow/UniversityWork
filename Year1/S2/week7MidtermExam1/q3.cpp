// Poker Card
#include <bits/stdc++.h>
class PokerCard
{
public:
    PokerCard(std::string s, int f)
    {
        suit = s;
        face = f;
    }
    friend std::ostream &operator<<(std::ostream &out, const PokerCard &p)
    {
        out << "[" << p.face << " of " << p.suit << "]";
        return out;
    }

    // Please finish the operator override
    // spade > heart > diamond > club
    // 1 > 13 > 12 > 11 > 10 > 9 > 8 > 7 > 6 > 5 > 4 > 3 > 2
    bool operator>(PokerCard &b)
    {
        if (this->face == 1)
        {
            if (b.face == 1)
            {
                if (this->suit > b.suit)
                    return 1;
                else
                    return 0;
            }
            return 1;
        }
        else
        {
            if (b.face == 1)
                return 0;
            else if (this->face > b.face)
                return 1;
            else if (this->face == b.face)
            {
                if (this->suit > b.suit)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
    }
    bool operator<(PokerCard &b)
    {
        if (this->face == 1)
        {
            if (b.face == 1)
            {
                if (this->suit < b.suit)
                    return 1;
                else
                    return 0;
            }
            return 0;
        }
        else
        {
            if (b.face == 1)
                return 1;
            else if (this->face < b.face)
                return 1;
            else if (this->face == b.face)
            {
                if (this->suit < b.suit)
                    return 1;
                else
                    return 0;
            }
            else
                return 0;
        }
    }
    bool operator==(PokerCard &b)
    {
        if (this->suit == b.suit and this->face == b.face)
            return 1;
        else
            return 0;
    }

private:
    std::string suit;
    int face;
};

int main()
{
    PokerCard **card = (PokerCard **)malloc(sizeof(PokerCard *) * 52);

    std::string s[] = {"spade", "heart", "diamond", "club"};
    int j, k;
    for (j = 0; j < 4; j++)
        for (k = 1; k <= 13; k++)
            card[j * 13 + k - 1] = new PokerCard(s[j], k);
    for (j = 0; j < 52; j++)
    {
        for (k = 0; k < 52; k++)
        {
            std::cout << *(card[j]) << ">" << *(card[k]) << ":" << (*(card[j]) > *(card[k])) << std::endl;
            std::cout << *(card[j]) << "<" << *(card[k]) << ":" << (*(card[j]) < *(card[k])) << std::endl;
            std::cout << *(card[j]) << "==" << *(card[k]) << ":" << (*(card[j]) == *(card[k])) << std::endl;
        }
    }
}