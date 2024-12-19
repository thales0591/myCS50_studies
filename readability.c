#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    string text = get_string("Text: ");
    float letters = 0;
    float words = 1;
    float phrases = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if(text[i] >= 'a' && text[i] <= 'z' || text[i] >= 'A' && text[i] <= 'Z')
        {
             letters += 1;
        }
       else if (text[i] == ' ')
       {
            words += 1;
       }
       else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
       {
            phrases += 1;
       }
    }
    float L = (letters * 100) / words;
    float S = (phrases * 100) / words;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);
    int intIndex = (int) index;
    if (intIndex <= 0)
    {
        printf("Before Grade 1");
    }
    else if (intIndex >= 16)
    {
        printf("Grade 16+");
    }
    else 
    {
        printf("Grade %i", intIndex);
    }
}