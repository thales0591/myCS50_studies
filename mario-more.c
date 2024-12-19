#include <stdio.h>
#include <cs50.h>

int main(void) {

    int heigth = get_int("Heigth: ");

    while (heigth <= 0 || heigth > 8)
    {
        heigth = get_int("Heigth: ");
    }

    int aux = heigth;

    for (int i = 0; i < heigth; i++)
    {
        for (int k = 1; k < aux; k++)
        {
            printf(" ");
        }

        aux -= 1;

        for (int j = i + 1; j > 0; j--)
        {
            printf("#");
        }

        printf("  ");

        for (int l = i + 1; l > 0; l--)
        {
            printf("#");
        }

        printf("\n");
    }
}
