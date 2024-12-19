#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    for(int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 2;
        }
    }
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");
    int key = atoi(argv[1]);
    int currentNumber = 0;
    for (int j = 0, length = strlen(plaintext); j < length; j++)
    {
        currentNumber = (int) plaintext[j] + key;
        if (currentNumber >= 122)
        {
            currentNumber = 97 + key - (122 - (int) plaintext[j]);
        }
        else if (currentNumber >= 90 && (plaintext[j] >= 'A' && plaintext[j] >= 'Z'))
        printf("%c", (int) plaintext[j] + atoi(argv[1]));
    }
    printf("\n");
}
