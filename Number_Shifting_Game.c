#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    int i, j, k, l, choice, random_variable, moves_remaining, player_move, flag, matrix[4][4], base_matrix[4][4];
    char player_name[30];
    k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            base_matrix[i][j] = k;
            k++;
        }
    }
    base_matrix[3][3] = ' ';
    printf("=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=> WELCOME TO NUMBER SHIFTING GAME <=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=\n\n");
    printf("Rules of this GAME are:\n1. A 4x4 matrix will be given with numbers 1-15 which would be randomly positioned.\n2. You can move only 1 step at a time by pressing arrow keys\n   Move Up : by Up arrow key\n   Move Down : by Down arrow key\n   Move Right : by Right arrow key\n   Move Left : by Left arrow key\n3. You can move number at empty position only.\n4. You will be given 400 moves.\n5. For each valid move your total number of moves will be decreased by 1\n6. Your task is to arrange the numbers in increasing order with minimum number of moves.\n\nWinning situation :\n");
    print_matrix(base_matrix);
    printf("\n\nEnter any key to START THE GAME\nBEST OF LUCK\n");
    getch();
    system("cls");
    printf("Enter player's name : ");
    fgets(player_name, 30, stdin);
    player_name[strlen(player_name) - 1] = '\0';
replay:
    moves_remaining = 400;
    // Generation of random variable and putting in the matrix;
    srand(time(NULL));
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            flag = 0;
            if (i == 3 && j == 3)
            {
                matrix[3][3] = ' ';
                goto end;
            }
            random_variable = rand() % 15 + 1;
            for (k = 0; k <= i; k++)
            {
                for (l = 0; l <= 3; l++)
                {
                    if (k == i && l == j)
                    {
                        break;
                    }
                    else if (random_variable == matrix[k][l])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    j--;
                    break;
                }
            }
            if (flag == 0)
            {
                matrix[i][j] = random_variable;
            }
        }
    }
end:
    for (;;)
    {
        system("cls");
        printf("Hello! %s         Your remaining moves : %d\n", player_name, moves_remaining);
        print_matrix(matrix);
        printf("\nMove the numbers by using arrow keys (You can exit the game anytime by pressing letter 'e' or 'E')\n");
    try_again:
        fflush(stdin);
        player_move = getch();
        if (player_move == 'e' || player_move == 'E') // EXIT the game
        {
            printf("\nAre you sure to EXIT if yes press 'y' or 'Y' OR if you want to replay then press 'r' or 'R' OR want to continue then press any other key\n");
            choice = getch();
            if (choice == 'y' || choice == 'Y')
                break;
            else if (choice == 'r' || choice == 'R')
                goto replay;
            else
            {
                printf("Please CONTINUE the GAME\n");
                goto try_again;
            }
        }
        else if ((player_move != 72 && player_move != 224) || (player_move != 80 && player_move != 224) || (player_move != 77 && player_move != 224) || (player_move != 75 && player_move != 224)) // Invalid Input
        {
            printf("\nINVALID INPUT\nYou can navigate only by using arrow keys or can exit the game by pressing 'e' or 'E'\nPlease try again!!!\n");
            goto try_again;
        }
        player_move = getch();
        switch (player_move)
        {
        case 72: // UP KEY
        {
            if (player_action(72, matrix))
            {
                printf("\nINVALID MOVE  Please try again!!!\n");
                goto try_again;
            }
            moves_remaining--;
        }
        break;
        case 80: // DOWN KEY
        {
            if (player_action(80, matrix))
            {
                printf("\nINVALID MOVE  Please try again!!!\n");
                goto try_again;
            }
            moves_remaining--;
        }
        break;
        case 77: // RIGHT KEY
        {
            if (player_action(77, matrix))
            {
                printf("\nINVALID MOVE  Please try again!!!\n");
                goto try_again;
            }
            moves_remaining--;
        }
        break;
        case 75: // LEFT KEY
        {
            if (player_action(75, matrix))
            {
                printf("\nINVALID MOVE  Please try again!!!\n");
                goto try_again;
            }
            moves_remaining--;
        }
        break;
        default:
        {
            printf("\nINVALID INPUT\nYou can navigate only by using arrow keys or can exit the game by pressing 'e' or 'E'\nPlease try again!!!\n");
            goto try_again;
        }
        }
        // checking the status of the matrix.
        flag = 0;
        for (i = 0; i < 4; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (matrix[i][j] != base_matrix[i][j])
                {
                    flag = 1;
                    break;
                }
                if (flag == 1)
                {
                    break;
                }
            }
        }
        if (flag == 0)
        {
            printf("\nYOU WIN THE GAME\n\nPress 'r' or 'R' for replay OR press any other key to exit\n");
            choice = getch();
            if (choice == 'r' || choice == 'R')
                goto replay;
            else
                break;
        }
        else if (moves_remaining == 0)
        {
            system("cls");
            printf("Hello! %s         Your remaining moves : %d\n", player_name, moves_remaining);
            print_matrix(matrix);
            printf("\nYOU LOSE THE GAME\n\nPress 'r' or 'R' for replay OR press any other key to exit\n");
            choice = getch();
            if (choice == 'r' || choice == 'R')
                goto replay;
            else
                break;
        }
    }
}
void print_matrix(int matrix[][4])
{
    int i, j;
    printf("\n ---------------\n");
    for (i = 0; i < 4; i++)
    {
        printf(" | ");
        for (j = 0; j < 4; j++)
        {
            printf("%-3d", matrix[i][j]);
            if (matrix[i][j] == ' ')
                printf("\b\b\b%-3c", ' ');
        }
        printf("|\n");
    }
    printf(" ---------------");
}
int player_action(int keystroke, int matrix[][4])
{
    int i, j, m, n, temp;
    for (i = 0; i <= 3; i++)
    {
        for (j = 0; j <= 3; j++)
        {
            if (matrix[i][j] == ' ')
            {
                m = i, n = j;
            }
        }
    }
    if (keystroke == 72) // UP KEY Action
    {
        if (m == 3)
            return 1;
        matrix[m][n] = matrix[m + 1][n];
        matrix[m + 1][n] = ' ';
        return 0;
    }
    else if (keystroke == 80) // DOWN KEY Action
    {
        if (m == 0)
            return 1;
        matrix[m][n] = matrix[m - 1][n];
        matrix[m - 1][n] = ' ';
        return 0;
    }
    else if (keystroke == 77) // RIGHT KEY Action
    {
        if (n == 0)
            return 1;
        matrix[m][n] = matrix[m][n - 1];
        matrix[m][n - 1] = ' ';
        return 0;
    }
    else if (keystroke == 75) // LEFT KEY Action
    {
        if (n == 3)
            return 1;
        matrix[m][n] = matrix[m][n + 1];
        matrix[m][n + 1] = ' ';
        return 0;
    }
}
