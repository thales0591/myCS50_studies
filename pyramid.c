#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int heigth = get_int("What heigth do you want? ");
    for (int i = 0; i < heigth; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    }
}
