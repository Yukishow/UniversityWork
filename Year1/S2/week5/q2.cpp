// UVA 852 Deciding victory in Go
#include <bits/stdc++.h>
using namespace std;
char board[9][10];
int boundO,boundX;
int eval;
void judge(int x,int y)
{
    if (x<0 or x>=9 or y<0 or y>=9) return;
    else if (board[x][y]=='.')
    {
        board[x][y]='0';
        eval++;
        judge(x+1,y);judge(x-1,y);
        judge(x,y-1);judge(x,y+1);
        return;
    }
    else if (board[x][y]=='O')
    {
        boundO=1;
        return;
    }
    else if (board[x][y]=='X')
    {
        boundX=1;
        return;
    }
    return;
}
int main(){
    int n;
    cin >> n;
    while (n--){
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                cin >> board[i][j];
            }
        }
        int B=0,W=0;
        for (int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                if (board[i][j]=='O') W++;
                else if (board[i][j]=='X') B++;
                else if (board[i][j]=='.')
                {
                    eval=0;
                    boundO=0;boundX=0;
                    judge(i,j);
                    if (boundO==1 and boundX==0) W+=eval;
                    else if (boundO==0 and boundX==1) B+=eval;
                }
            }
        }
        cout << "Black " << B << " White " << W << endl;
    }

    return 0;
}