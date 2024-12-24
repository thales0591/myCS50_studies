#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    //check if the number of arguments is different of 2
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if ((int) strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    char alphabet[26] = {0};
    //check if there is any non-digit in the argument
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Numeric values are not allowed.\n");
            return 1;
        }
        if (i == 0)
        {
            alphabet[0] = argv[1][0];
        }
        else
        {
        for (int j = 0; j < i; j++)
        {
            if (alphabet[j] == argv[1][i])
            {
                printf("Repeated characters are not allowed.\n");
                return 1;
            }
        }
        alphabet[i] = argv[1][i];
        }
    }
    char plaintext[] = "This is CS50";
    char defaultUppercaseAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char defaultLowercaseAlphabet[] = "abcdefghijklmnopqrstuvwxyz";
    printf("ciphertext:  ");
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (plaintext[i] < 65 || plaintext[i] > 122 || (plaintext[i] >= 91 && plaintext[i] <= 96))
        {
            printf("%c", plaintext[i]);
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                if (defaultUppercaseAlphabet[j] == plaintext[i] || defaultLowercaseAlphabet[j] == plaintext[i])
                {
                    if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
                    {
                        if (alphabet[j] >= 'A' && alphabet[j] <= 'Z' )
                        {
                            printf("%c", alphabet[j]);
                        }
                        else
                        {
                            printf("%c", alphabet[j] - 32);
                        }
                    }
                    else
                    {
                        if (alphabet[j] >= 'a' && alphabet[j] <= 'z' )
                        {
                            printf("%c", alphabet[j]);
                        }
                        else
                        {
                            printf("%c", alphabet[j] + 32);
                        }
                    }
                } 
            }
        }
    }    
    printf("\n");
}
