#include <cs50.h>
#include <stdio.h>
#include <string.h>

int score(char play[], int playerScore);

int main(void)
{
    int score1 = 0, score2 = 0;
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");
    score1 = score(player1, score1);
    score2 = score(player2, score2);
    //winner logic
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//function that returns player score

int score(char play[], int playerScore)
{
    for (int i = 0, length = strlen(play); i < length; i++)
    {
        if ((play[i] >= 'r' && play[i] <= 'u') || play[i] == 'a' || play[i] == 'e' ||
            play[i] == 'i' || play[i] == 'l' || play[i] == 'n' || play[i] == 'o' ||
            (play[i] >= 'R' && play[i] <= 'U') || play[i] == 'A' || play[i] == 'E' ||
            play[i] == 'I' || play[i] == 'L' || play[i] == 'N' || play[i] == 'O')
        {
            playerScore += 1;
        }
        else if (play[i] == 'd' || play[i] == 'g' || play[i] == 'D' || play[i] == 'G')
        {
            playerScore += 2;
        }
        else if (play[i] == 'b' || play[i] == 'c' || play[i] == 'm' || play[i] == 'p' ||
                 play[i] == 'B' || play[i] == 'C' || play[i] == 'M' || play[i] == 'P')
        {
            playerScore += 3;
        }
        else if (play[i] == 'f' || play[i] == 'h' || play[i] == 'v' || play[i] == 'w' ||
                 play[i] == 'y' || play[i] == 'F' || play[i] == 'H' || play[i] == 'V' ||
                 play[i] == 'W' || play[i] == 'Y')
        {
            playerScore += 4;
        }
        else if (play[i] == 'k' || play[i] == 'K')
        {
            playerScore += 5;
        }
        else if (play[i] == 'j' || play[i] == 'x' || play[i] == 'J' || play[i] == 'X')
        {
            playerScore += 8;
        }
        else if (play[i] == 'q' || play[i] == 'z' || play[i] == 'Q' || play[i] == 'Z')
        {
            playerScore += 10;
        }
    }
    return playerScore;
}
