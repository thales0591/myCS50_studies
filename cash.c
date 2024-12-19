#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int money = get_int("Change owed: ");
    int count = 0;
    while (money <= 0)
    {
        money = get_int("Change owed: \n");
    }
    while (money >= 25)
    {
        money -= 25;
        count += 1;
    }

    while (money >= 10)
    {
        money -= 10;
        count += 1;
    }

    while (money >= 5)
    {
        money -= 5;
        count += 1;
    }

    while (money >= 1)
    {
        money -= 1;
        count += 1;
    }
    printf("%i\n", count);
}
