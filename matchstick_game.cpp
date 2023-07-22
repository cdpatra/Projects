#include <iostream>
#include <stdlib.h>
#include <conio.h>

int main()
{
    system("cls");
    int computer, user, match = 21;
    std::cout << "******************** WELCOME TO THE MATCHSTICKS GAME *********************\n\n\n";
    std::cout << "The rules for the game are as follows:-\n-There are 21 Matchsticks.\n-The computer ask the player to pick 1,2,3 or 4 Matchsticks.\n-After the person picks, the computer does its picking.\n-Whoever is forced to pick up the last Matchstick loses the game.\n\n\nPress any key to start the game :-)\n";
    getch();
    std::cout << "Total number of MATCHSTICKS are:- " << match << "\n";
    std::cout << "Pick the MATCHSTICS (You can pick either 1,2,3 or 4 MATCHSTIKS)\n";
    for (;;)
    {
        std::cin >> user;
        if (user <= 4 && user > 0)
            break;
        std::cout << "invalid input\nYou can pick either 1,2,3 or 4 MATCHSTIKS\nPlease try again\nPick the MATCHSTICKS (You can pick either 1,2,3 or 4 MATCHSTIKS)\n";
    }
    for (;;)
    {
        match = match - user;
        computer = 4;
        if (match > 15)
        {
            for (; match - computer != 16;)
            {
                if (match - computer <= 16)
                    computer--;
            }
        }
        if (match <= 15)
        {
            for (; match - computer != 11;)
            {
                if (match - computer <= 11)
                    computer--;
            }
        }
        if (match < 11)
            computer = (match % 6);
        if (match < 6)
            computer = (match % 6) - 1;
        if (computer == 0)
            computer++;
        match = match - computer;
        std::cout << "COMPUTER picks " << computer << " MATCHSTICKS\n\n"
                  << "Remaining MATCHSTICKS are " << match << "\n";
        if (match == 1)
        {
            std::cout << "\n You are forced to pick the last MATCHSTICK\n\nYOU LOSE THE GAME :-(";
            break;
        }
        std::cout << "Now your turn\n\nPick the MATCHSTICS (You can pick either 1,2,3 or 4 MATCHSTIKS)\n";
        for (;;)
        {
            std::cin >> user;
            if (user <= 4 && user > 0)
                break;
            std::cout << "invalid input\nYou can pick either 1,2,3 or 4 MATCHSTIKS\nPlease try again\nPick the MATCHSTICKS (You can pick either 1,2,3 or 4 MATCHSTIKS)\n";
        }
    }
    std::cout << "\n\nPress any key to EXIT\nmade by CDPATRA :-)";
    getch();
}