#include <stdio.h>
int main()
{
    int array[9];
    while (scanf("%d",&array[0]) !=EOF)
    {
        for (int i=1;i<9;i++)
        {
            scanf("%d",&array[i]);
        }
        if ((array[0]==array[1] && array[1]==array[2] && array[2]==1) || (array[3]==array[4] && array[4]==array[5] && array[5]==1)\
         || (array[6]==array[7] && array[7]==array[8] && array[8]==1) ||(array[0]==array[3] && array[3]==array[6] && array[6]==1)\
          || (array[1]==array[4] && array[4]==array[7] && array[7]==1) || (array[2]==array[5] && array[5]==array[8] && array[8]==1) ||\
            (array[0]==array[4] && array[4]==array[8] && array[8]==1) || (array[2]==array[4] && array[4]==array[6] && array[6]==1)) 
            printf("Player 1 win.\n");
        else if((array[0]==array[1] && array[1]==array[2] && array[2]==2) || (array[3]==array[4] && array[4]==array[5] && array[5]==2)\
         || (array[6]==array[7] && array[7]==array[8] && array[8]==2) ||(array[0]==array[3] && array[3]==array[6] && array[6]==2)\
          || (array[1]==array[4] && array[4]==array[7] && array[7]==2) || (array[2]==array[5] && array[5]==array[8] && array[8]==2) ||\
            (array[0]==array[4] && array[4]==array[8] && array[8]==2) || (array[2]==array[4] && array[4]==array[6] && array[6]==2))
            printf("Player 2 win.\n");
        else
            printf("No winner.\n");
    }
    
    return 0;
}