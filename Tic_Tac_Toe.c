// header files and preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#define PLAYER_1 'X'
#define PLAYER_2 'O'

// global declarations
void Print_Grid(char[]);
int Check_Grid();
int Smart_Computer();
void won(char player_name[]);
void draw();
int Evil_Computer();

struct Grid_block
{
    int a, b;
} ttt[3][3];
// global variables
char Player_1_name[30], Player_2_name[30];
int main()
{
    int i, j, k = 1, player_choice;
    struct Grid_block position, count_Player_moves;
    extern char Player_1_name[30], Player_2_name[30];
    extern struct Grid_block ttt[3][3];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ttt[i][j].a = k;
            ttt[i][j].b = k;
            k++;
        }
    }
    printf("=>=>=>=>=>=>=>=>=>=>=>=>=> Welcome to TIC TAC TOE GAME <=<=<=<=<=<=<=<=<=<=<=<=<=<=<=\n\n");
    printf("Direction to play:-\n");
    for (i = 0; i < 3; i++)
    {
        printf("                                      |     |\n");
        printf("                                   %d", ttt[i][0].a);
        printf("  |  ");
        printf("%d", ttt[i][1].a);
        printf("  |  ");
        printf("%d\n", ttt[i][2].a);
        if (i <= 1)
            printf("                                 _____|_____|_____\n");
        else
            printf("                                      |     |\n");
    }
    printf("1. There is a grid made up of 2 horizontal and 2 vertical lines which create 9 blocks as shown above.\n");
    printf("2. Each block has its own number.\n");
    printf("3. The symbol of Player 1 is X and the symbol of player 2 is O.\n");
    printf("4. You have to choose the block number to mark the respective block.\n");
    printf("BEST OF LUCK\nEnter any key to start the game\n");
    getch();
    system("cls");
replay:
    k = 1;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ttt[i][j].a = k;
            ttt[i][j].b = k;
            k++;
        }
    }
    printf("Please Enter your choice:\n");
    printf("1. Want to play with smart computer.\n");
    printf("2. Want to play with evil computer.\n");
    printf("3. Want to play with player.\n");
    printf("4. Exit.\n");
    scanf("%d", &player_choice);
    switch (player_choice)
    {
    case 1:
    {
        printf("Enter player 1's name: ");
        fflush(stdin);
        fgets(Player_1_name, 30, stdin);
        Player_1_name[strlen(Player_1_name) - 1] = '\0';
        strcpy(Player_2_name, "Smart Computer");
        for (;;)
        {
            extern struct Grid_block ttt[3][3];
            extern char Player_1_name[30], Player_2_name[30];
            Print_Grid(Player_1_name); // player-1 move.
            if (Check_Grid())
                break;
            else if (Smart_Computer())
                break;
        }
        break;
    }
    case 2:
    {
        printf("Enter player 1's name: ");
        fflush(stdin);
        fgets(Player_1_name, 30, stdin);
        Player_1_name[strlen(Player_1_name) - 1] = '\0';
        strcpy(Player_2_name, "Evil Computer");
        for (;;)
        {
            extern struct Grid_block ttt[3][3];
            extern char Player_1_name[30], Player_2_name[30];
            Print_Grid(Player_1_name); // player-1 move.
            if (Check_Grid())
                break;
            else if (Evil_Computer())
                break;
            if (Check_Grid())
                break;
        }
        break;
    }
    case 3:
    {
        printf("Enter player 1's name: ");
        fflush(stdin);
        fgets(Player_1_name, 30, stdin);
        Player_1_name[strlen(Player_1_name) - 1] = '\0';
        printf("Enter player 2's name: ");
        fflush(stdin);
        fgets(Player_2_name, 30, stdin);
        Player_2_name[strlen(Player_2_name) - 1] = '\0';
        k--;
        for (;;)
        {
            extern struct Grid_block ttt[3][3];
            extern char Player_1_name[30], Player_2_name[30];
            Print_Grid(Player_1_name); // player-1 move.
            if (Check_Grid())
                break;
            Print_Grid(Player_2_name); // player-2 move.
            if (Check_Grid())
                break;
        }
        break;
    }
    case 4:
    {
        break;
    }
    default:
    {
        system("cls");
        printf("Invalid Input !!!\n\n");
        goto replay;
    }
    }
    if (player_choice != 4)
    {
        for (;;)
        {
            printf("\n\nWant a replay ?\nIf yes enter 'y' or 'Y' if no enter 'n' or 'N'\n");
            fflush(stdin);
            scanf("%c", &player_choice);
            if (player_choice == 'y' || player_choice == 'Y')
            {
                system("cls");
                goto replay;
            }
            else if (player_choice == 'n' || player_choice == 'N')
                break;
            else
                printf("Invalid Input !!!\n");
        }
    }
}
int Check_Grid()
{
    extern struct Grid_block ttt[3][3];
    extern char Player_1_name[30], Player_2_name[30];
    int i, j, count_Player_1_moves, count_Player_2_moves, count = 0;
    // checking rows
    for (i = 0; i < 3; i++)
    {
        count_Player_1_moves = 0;
        count_Player_2_moves = 0;
        for (j = 0; j < 3; j++)
        {
            if (ttt[i][j].a == PLAYER_1)
                count_Player_1_moves++; // Number of moves by Player 1
            if (ttt[i][j].a == PLAYER_2)
                count_Player_2_moves++; // Number of moves by Player 2
        }
        if (count_Player_1_moves == 3)
        {
            won(Player_1_name);
            return 1;
        }
        else if (count_Player_2_moves == 3)
        {
            won(Player_2_name);
            return 1;
        }
    }
    // checking columns
    for (j = 0; j < 3; j++)
    {
        count_Player_1_moves = 0;
        count_Player_2_moves = 0;
        for (i = 0; i < 3; i++)
        {
            if (ttt[i][j].a == PLAYER_1)
                count_Player_1_moves++; // Number of moves by Player 1
            if (ttt[i][j].a == PLAYER_2)
                count_Player_2_moves++; // Number of moves by Player 2
        }
        if (count_Player_1_moves == 3)
        {
            won(Player_1_name);
            return 1;
        }
        else if (count_Player_2_moves == 3)
        {
            won(Player_2_name);
            return 1;
        }
    }
    // checking diagnols
    if (ttt[0][0].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[2][2].a == PLAYER_1)
    {
        won(Player_1_name);
        return 1;
    }
    else if (ttt[0][2].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[2][0].a == PLAYER_1)
    {
        won(Player_1_name);
        return 1;
    }
    else if (ttt[0][0].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[2][2].a == PLAYER_2)
    {
        won(Player_2_name);
        return 1;
    }
    else if (ttt[0][2].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[2][0].a == PLAYER_2)
    {
        won(Player_2_name);
        return 1;
    }
    // checking for draw
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (ttt[i][j].a != ttt[i][j].b)
                count++;
        }
    }
    if (count == 9)
    {
        draw();
        return 1;
    }
    return 0;
}
int Smart_Computer()
{
    extern char Player_1_name[30], Player_2_name[30];
    int i, j, flag = 0;
    // making move in rows for winning
    for (i = 0; i < 3; i++)
    {
        if (ttt[i][0].a == PLAYER_2 && ttt[i][1].a == PLAYER_2 && ttt[i][2].a != PLAYER_1)
        {
            ttt[i][2].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[i][1].a == PLAYER_2 && ttt[i][2].a == PLAYER_2 && ttt[i][0].a != PLAYER_1)
        {
            ttt[i][0].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[i][0].a == PLAYER_2 && ttt[i][2].a == PLAYER_2 && ttt[i][1].a != PLAYER_1)
        {
            ttt[i][1].a = PLAYER_2;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        won(Player_2_name);
        return 1;
    }
    // making move in columns for winning
    for (i = 0; i < 3; i++)
    {
        if (ttt[0][i].a == PLAYER_2 && ttt[1][i].a == PLAYER_2 && ttt[2][i].a != PLAYER_1)
        {
            ttt[2][i].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[2][i].a == PLAYER_2 && ttt[1][i].a == PLAYER_2 && ttt[0][i].a != PLAYER_1)
        {
            ttt[0][i].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[0][i].a == PLAYER_2 && ttt[2][i].a == PLAYER_2 && ttt[1][i].a != PLAYER_1)
        {
            ttt[1][i].a = PLAYER_2;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        won(Player_2_name);
        return 1;
    }
    // making move in diagnols for winning
    if (ttt[0][0].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[2][2].a != PLAYER_1)
    {
        ttt[2][2].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[2][2].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[0][0].a != PLAYER_1)
    {
        ttt[0][0].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[0][0].a == PLAYER_2 && ttt[2][2].a == PLAYER_2 && ttt[1][1].a != PLAYER_1)
    {
        ttt[1][1].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[0][2].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[2][0].a != PLAYER_1)
    {
        ttt[2][0].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[2][0].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[0][2].a != PLAYER_1)
    {
        ttt[0][2].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[0][2].a == PLAYER_2 && ttt[2][0].a == PLAYER_2 && ttt[1][1].a != PLAYER_1)
    {
        ttt[1][1].a = PLAYER_2;
        flag = 1;
    }
    if (flag == 1)
    {
        won(Player_2_name);
        return 1;
    }
    // making moves in rows for defending
    for (i = 0; i < 3; i++)
    {
        if (ttt[i][0].a == PLAYER_1 && ttt[i][1].a == PLAYER_1 && ttt[i][2].a != PLAYER_2)
        {
            ttt[i][2].a = PLAYER_2;
            return 0;
        }
        else if (ttt[i][1].a == PLAYER_1 && ttt[i][2].a == PLAYER_1 && ttt[i][0].a != PLAYER_2)
        {
            ttt[i][0].a = PLAYER_2;
            return 0;
        }
        else if (ttt[i][0].a == PLAYER_1 && ttt[i][2].a == PLAYER_1 && ttt[i][1].a != PLAYER_2)
        {
            ttt[i][1].a = PLAYER_2;
            return 0;
        }
    }
    // making moves in columns for defending
    for (i = 0; i < 3; i++)
    {
        if (ttt[0][i].a == PLAYER_1 && ttt[1][i].a == PLAYER_1 && ttt[2][i].a != PLAYER_2)
        {
            ttt[2][i].a = PLAYER_2;
            return 0;
        }
        else if (ttt[2][i].a == PLAYER_1 && ttt[1][i].a == PLAYER_1 && ttt[0][i].a != PLAYER_2)
        {
            ttt[0][i].a = PLAYER_2;
            return 0;
        }
        else if (ttt[0][i].a == PLAYER_1 && ttt[2][i].a == PLAYER_1 && ttt[1][i].a != PLAYER_2)
        {
            ttt[1][i].a = PLAYER_2;
            return 0;
        }
    }

    // makeing move in diagnols for defending
    if (ttt[0][0].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[2][2].a != PLAYER_2)
    {
        ttt[2][2].a = PLAYER_2;
        return 0;
    }
    else if (ttt[2][2].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[0][0].a != PLAYER_2)
    {
        ttt[0][0].a = PLAYER_2;
        return 0;
    }
    else if (ttt[0][0].a == PLAYER_1 && ttt[2][2].a == PLAYER_1 && ttt[1][1].a != PLAYER_2)
    {
        ttt[1][1].a = PLAYER_2;
        return 0;
    }
    else if (ttt[0][2].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[2][0].a != PLAYER_2)
    {
        ttt[2][0].a = PLAYER_2;
        return 0;
    }
    else if (ttt[2][0].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[0][2].a != PLAYER_2)
    {
        ttt[0][2].a = PLAYER_2;
        return 0;
    }
    else if (ttt[0][2].a == PLAYER_1 && ttt[2][0].a == PLAYER_1 && ttt[1][1].a != PLAYER_2)
    {
        ttt[1][1].a = PLAYER_2;
        return 0;
    }
    // if none of the above move take place
    for (;;)
    {
        int i, j;
        srand(time(NULL));
        i = rand() % 3;
        j = rand() % 3;
        if (ttt[i][j].a != PLAYER_1 && ttt[i][j].a != PLAYER_2)
        {
            ttt[i][j].a = PLAYER_2;
            return 0;
        }
    }
}
int Evil_Computer()
{
    extern char Player_1_name[30], Player_2_name[30];
    int i, j, flag = 0;
    // making move in rows for winning
    for (i = 0; i < 3; i++)
    {
        if (ttt[i][0].a == PLAYER_2 && ttt[i][1].a == PLAYER_2 && ttt[i][2].a != PLAYER_1)
        {
            ttt[i][2].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[i][1].a == PLAYER_2 && ttt[i][2].a == PLAYER_2 && ttt[i][0].a != PLAYER_1)
        {
            ttt[i][0].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[i][0].a == PLAYER_2 && ttt[i][2].a == PLAYER_2 && ttt[i][1].a != PLAYER_1)
        {
            ttt[i][1].a = PLAYER_2;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        won(Player_2_name);
        return 1;
    }
    // making move in columns for winning
    for (i = 0; i < 3; i++)
    {
        if (ttt[0][i].a == PLAYER_2 && ttt[1][i].a == PLAYER_2 && ttt[2][i].a != PLAYER_1)
        {
            ttt[2][i].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[2][i].a == PLAYER_2 && ttt[1][i].a == PLAYER_2 && ttt[0][i].a != PLAYER_1)
        {
            ttt[0][i].a = PLAYER_2;
            flag = 1;
        }
        else if (ttt[0][i].a == PLAYER_2 && ttt[2][i].a == PLAYER_2 && ttt[1][i].a != PLAYER_1)
        {
            ttt[1][i].a = PLAYER_2;
            flag = 1;
        }
    }
    if (flag == 1)
    {
        won(Player_2_name);
        return 1;
    }
    // making move in diagnols for winning
    if (ttt[0][0].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[2][2].a != PLAYER_1)
    {
        ttt[2][2].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[2][2].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[0][0].a != PLAYER_1)
    {
        ttt[0][0].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[0][0].a == PLAYER_2 && ttt[2][2].a == PLAYER_2 && ttt[1][1].a != PLAYER_1)
    {
        ttt[1][1].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[0][2].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[2][0].a != PLAYER_1)
    {
        ttt[2][0].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[2][0].a == PLAYER_2 && ttt[1][1].a == PLAYER_2 && ttt[0][2].a != PLAYER_1)
    {
        ttt[0][2].a = PLAYER_2;
        flag = 1;
    }
    else if (ttt[0][2].a == PLAYER_2 && ttt[2][0].a == PLAYER_2 && ttt[1][1].a != PLAYER_1)
    {
        ttt[1][1].a = PLAYER_2;
        flag = 1;
    }
    if (flag == 1)
    {
        won(Player_2_name);
        return 1;
    }
    // making moves in rows for defending
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (ttt[i][0].a == PLAYER_1 && ttt[i][1].a == PLAYER_1 && ttt[i][2].a != PLAYER_2)
            {
                ttt[i][2].a = PLAYER_2;
                flag = 2;
            }
            else if (ttt[i][1].a == PLAYER_1 && ttt[i][2].a == PLAYER_1 && ttt[i][0].a != PLAYER_2)
            {
                ttt[i][0].a = PLAYER_2;
                flag = 2;
            }
            else if (ttt[i][0].a == PLAYER_1 && ttt[i][2].a == PLAYER_1 && ttt[i][1].a != PLAYER_2)
            {
                ttt[i][1].a = PLAYER_2;
                flag = 2;
            }
        }
    }
    // making moves in columns for defending
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 3; i++)
        {
            if (ttt[0][i].a == PLAYER_1 && ttt[1][i].a == PLAYER_1 && ttt[2][i].a != PLAYER_2)
            {
                ttt[2][i].a = PLAYER_2;
                flag = 2;
            }
            else if (ttt[2][i].a == PLAYER_1 && ttt[1][i].a == PLAYER_1 && ttt[0][i].a != PLAYER_2)
            {
                ttt[0][i].a = PLAYER_2;
                flag = 2;
            }
            else if (ttt[0][i].a == PLAYER_1 && ttt[2][i].a == PLAYER_1 && ttt[1][i].a != PLAYER_2)
            {
                ttt[1][i].a = PLAYER_2;
                flag = 2;
            }
        }
    }

    // makeing move in diagnols for defending
    for (j = 0; j < 2; j++)
    {
        if (ttt[0][0].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[2][2].a != PLAYER_2)
        {
            ttt[2][2].a = PLAYER_2;
            flag = 2;
        }
        else if (ttt[2][2].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[0][0].a != PLAYER_2)
        {
            ttt[0][0].a = PLAYER_2;
            flag = 2;
        }
        else if (ttt[0][0].a == PLAYER_1 && ttt[2][2].a == PLAYER_1 && ttt[1][1].a != PLAYER_2)
        {
            ttt[1][1].a = PLAYER_2;
            flag = 2;
        }
        else if (ttt[0][2].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[2][0].a != PLAYER_2)
        {
            ttt[2][0].a = PLAYER_2;
            flag = 2;
        }
        else if (ttt[2][0].a == PLAYER_1 && ttt[1][1].a == PLAYER_1 && ttt[0][2].a != PLAYER_2)
        {
            ttt[0][2].a = PLAYER_2;
            flag = 2;
        }
        else if (ttt[0][2].a == PLAYER_1 && ttt[2][0].a == PLAYER_1 && ttt[1][1].a != PLAYER_2)
        {
            ttt[1][1].a = PLAYER_2;
            flag = 2;
        }
    }
    if (flag == 2)
        return 0;

    // if none of the above move take place
    for (;;)
    {
        int i, j;
        srand(time(NULL));
        i = rand() % 3;
        j = rand() % 3;
        if (ttt[i][j].a != PLAYER_1 && ttt[i][j].a != PLAYER_2)
        {
            ttt[i][j].a = PLAYER_2;
            return 0;
        }
    }
}
void Print_Grid(char player_name[])
{
    system("cls");
    int i, j, player_choice;
    struct Grid_block position;
    extern struct Grid_block ttt[3][3];
    extern char Player_1_name[30], Player_2_name[30];
    printf("Player-1 is %s\n", Player_1_name);
    printf("Player-2 is %s\n\n", Player_2_name);
    printf("                       # # # #  Tic Tac Toe # # # #\n                       #                          #\n");
    for (i = 0; i < 3; i++)
    {
        if (i == 1)
            printf("Player-1: X            #          |     |         #\n");
        else
            printf("                       #          |     |         #\n");
        if (i == 1)
        {
            if (ttt[i][0].a == ttt[i][0].b)
                printf("Player-2: O            #       %d", ttt[i][0].a);
            else
                printf("Player-2: O            #       %c", ttt[i][0].a);
        }
        else
        {
            if (ttt[i][0].a == ttt[i][0].b)
                printf("                       #       %d", ttt[i][0].a);
            else
                printf("                       #       %c", ttt[i][0].a);
        }
        printf("  |  ");
        if (ttt[i][1].a == ttt[i][1].b)
            printf("%d", ttt[i][1].a);
        else
            printf("%c", ttt[i][1].a);
        printf("  |  ");
        if (ttt[i][2].a == ttt[i][2].b)
            printf("%d      #\n", ttt[i][2].a);
        else
            printf("%c      #\n", ttt[i][2].a);
        if (i <= 1)
            printf("                       #     _____|_____|_____    #\n");
        else
            printf("                       #          |     |         #\n");
    }
    printf("                       #                          #\n                       # # # #  Tic Tac Toe # # # #\n\n");
    for (;;)
    {
        printf("%s, Please choose your block by entering the respecive block number: ", player_name);
        fflush(stdin);
        scanf("%d", &player_choice);
        if (player_choice < 1 || player_choice > 9)
        {
            printf("INVALID INPUT !!!\n");
            continue;
        }
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (player_choice == ttt[i][j].a)
                {
                    if (strcmp(Player_1_name, player_name) == 0)
                    {
                        ttt[i][j].a = PLAYER_1;
                        return;
                    }
                    else
                    {
                        ttt[i][j].a = PLAYER_2;
                        return;
                    }
                }
            }
        }
        printf("This position is already occupied !!!\n");
    }
}
void won(char player_name[])
{
    system("cls");
    int i, j, player_choice;
    struct Grid_block position;
    extern struct Grid_block ttt[3][3];
    extern char Player_1_name[30], Player_2_name[30];
    printf("Player-1 is %s\n", Player_1_name);
    printf("Player-2 is %s\n\n", Player_2_name);
    printf("                       # # # #  Tic Tac Toe # # # #\n                       #                          #\n");
    for (i = 0; i < 3; i++)
    {
        if (i == 1)
            printf("Player-1: X            #          |     |         #\n");
        else
            printf("                       #          |     |         #\n");
        if (i == 1)
        {
            if (ttt[i][0].a == ttt[i][0].b)
                printf("Player-2: O            #        ", ttt[i][0].a);
            else
                printf("Player-2: O            #       %c", ttt[i][0].a);
        }
        else
        {
            if (ttt[i][0].a == ttt[i][0].b)
                printf("                       #        ", ttt[i][0].a);
            else
                printf("                       #       %c", ttt[i][0].a);
        }
        printf("  |  ");
        if (ttt[i][1].a == ttt[i][1].b)
            printf(" ", ttt[i][1].a);
        else
            printf("%c", ttt[i][1].a);
        printf("  |  ");
        if (ttt[i][2].a == ttt[i][2].b)
            printf("       #\n", ttt[i][2].a);
        else
            printf("%c      #\n", ttt[i][2].a);
        if (i <= 1)
            printf("                       #     _____|_____|_____    #\n");
        else
            printf("                       #          |     |         #\n");
    }
    printf("                       #                          #\n                       # # # #  Tic Tac Toe # # # #\n\n");
    printf("%s, WON THE GAME :-)\n", player_name);
}
void draw()
{
    system("cls");
    int i, j, player_choice;
    struct Grid_block position;
    extern struct Grid_block ttt[3][3];
    extern char Player_1_name[30], Player_2_name[30];
    printf("Player-1 is %s\n", Player_1_name);
    printf("Player-2 is %s\n\n", Player_2_name);
    printf("                       # # # #  Tic Tac Toe # # # #\n                       #                          #\n");
    for (i = 0; i < 3; i++)
    {
        if (i == 1)
            printf("Player-1: X            #          |     |         #\n");
        else
            printf("                       #          |     |         #\n");
        if (i == 1)
        {
            if (ttt[i][0].a == ttt[i][0].b)
                printf("Player-2: O            #        ", ttt[i][0].a);
            else
                printf("Player-2: O            #       %c", ttt[i][0].a);
        }
        else
        {
            if (ttt[i][0].a == ttt[i][0].b)
                printf("                       #        ", ttt[i][0].a);
            else
                printf("                       #       %c", ttt[i][0].a);
        }
        printf("  |  ");
        if (ttt[i][1].a == ttt[i][1].b)
            printf(" ", ttt[i][1].a);
        else
            printf("%c", ttt[i][1].a);
        printf("  |  ");
        if (ttt[i][2].a == ttt[i][2].b)
            printf("       #\n", ttt[i][2].a);
        else
            printf("%c      #\n", ttt[i][2].a);
        if (i <= 1)
            printf("                       #     _____|_____|_____    #\n");
        else
            printf("                       #          |     |         #\n");
    }
    printf("                       #                          #\n                       # # # #  Tic Tac Toe # # # #\n\n");
    printf("THIS MATCH IS DRAW\n");
}
