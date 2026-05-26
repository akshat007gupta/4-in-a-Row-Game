#include <stdio.h>
void printarr(int arr[6][7])
{
    for (int i = 0; i < 6; i++)
    {
        printf("|");
        for (int j = 0; j < 7; j++)
        {
            if (arr[i][j] == 0)
                printf(" . ");
            else if (arr[i][j] == 1)
                printf(" O ");
            else
                printf(" X ");
        }
        printf("|");
        printf("\n");
    }
    printf("\n");
}
int main()
{
    int player = 1;
    int column = 0, count_H = 0, l_row = 0, count_V = 0, count_L = 0, count_R = 0;
    int arr[6][7] = {0};
    // printarr(arr);
    for (int i = 0; i < 42; i++) // Change to while
    {
        printf("Enter the column number to drop the piece (1-7):");
        scanf("%d", &column);
        column = column % 7;
        count_H = 0; count_V = 0; count_R = 0; count_L = 0;
        if (column == 0)
        {
            column = 7;
        }
        for (int row = 5; row >= 0; row--) // block placement mechanism
        {
            if (arr[row][column - 1] == 0)
            {
                arr[row][column - 1] = player;
                l_row = row;
                break;
            }
        }
        int Lr = l_row; // Checking left digonal
        int Ll = column - 1;
        if ((5 - Lr) < Ll)
        {
            Ll = Ll - (5 - Lr);
            Lr = 5;
        }
        else
        {
            Lr = Lr + Ll;
            Ll = 0;
        }
        for (; Lr >= 0 && Ll < 7; Lr--, Ll++)
        {
            if (arr[Lr][Ll] == player)
                count_L++;
            else
                count_L = 0;
            if (count_L >= 4)
            {
                printf("Player %d Wins\n", player);
                goto exit_loop;
            }
        }
        int Rr = l_row; // Checking right digonal
        int Rl = column - 1;
        if (Rr < Rl)
        {
            Rl = Rl - Rr;
            Rr = 0;
        }
        else
        {
            Rr = Rr - Rl;
            Rl = 0;
        }
        for (Rl, Rr; Rr < 6 && Rl < 7; Rr++, Rl++)
        {
            if (arr[Rr][Rl] == player)
            {
                count_R++;
            }
            else
            {
                count_R = 0;
            }
            if (count_R >= 4)
            {
                printf("Player %d Wins \n", player);
                printf("\n");
                goto exit_loop;
            }
        }
        for (int i = 5; i >= 0; i--) // Vertical Checking
        {
            if (arr[i][column - 1] == player)
            {
                count_V++;
            }
            else
            {
                count_V = 0;
            }
            if (count_V >= 4)
            {
                printf("Player %d Wins \n", player);
                printf("\n");
                goto exit_loop;
            }
        }
        for (int i = 0; i < 7; i++) // Horizontal checking
        {
            if (arr[l_row][i] == player)
            {
                count_H++;
            }
            else
            {
                count_H = 0;
            }
            if (count_H >= 4)
            {
                printf("Player %d Wins \n", player);
                printf("\n");
                goto exit_loop;
            }
        }
        if (player == 1) // Player change code
        {
            player = 2;
        }
        else
        {
            player = 1;
        }
        printarr(arr);
    }
exit_loop:
    printarr(arr);
    printf("Player %d Wins !!!!!\n", player);
    return 0;
}
