#include <cs50.h>
#include <stdio.h>

void validation(long long number);

int main(void)
{
    long long credit = get_long("Number: ");
    validation(credit);
}

void validation(long long number)
{
    // 16 digits
    if ((number >= 4000000000000000 && number <= 4999999999999999) ||
        (number >= 5100000000000000 && number <= 5599999999999999))
    {
        long long int aux = number;
        long long n1 = aux % 100 / 10 * 2;
        long long n2 = aux % 10000 / 1000 * 2;
        long long n3 = aux % 1000000 / 100000 * 2;
        long long n4 = aux % 100000000 / 10000000 * 2;
        long long n5 = aux % 10000000000 / 1000000000 * 2;
        long long n6 = aux % 1000000000000 / 100000000000 * 2;
        long long n7 = aux % 100000000000000 / 10000000000000 * 2;
        long long n8 = aux / 1000000000000000 * 2;

        long long w1 = aux % 10;
        long long w2 = aux % 1000 / 100;
        long long w3 = aux % 100000 / 10000;
        long long w4 = aux % 10000000 / 1000000;
        long long w5 = aux % 1000000000 / 100000000;
        long long w6 = aux % 100000000000 / 10000000000;
        long long w7 = aux % 10000000000000 / 1000000000000;
        long long w8 = aux % 1000000000000000 / 100000000000000;

        if (n1 > 9)
        {
            int aux1 = n1 % 10;
            int aux2 = n1 / 10;
            n1 = aux1 + aux2;
        }
        if (n2 > 9)
        {
            int aux1 = n2 % 10;
            int aux2 = n2 / 10;
            n2 = aux1 + aux2;
        }
        if (n3 > 9)
        {
            int aux1 = n3 % 10;
            int aux2 = n3 / 10;
            n3 = aux1 + aux2;
        }
        if (n4 > 9)
        {
            int aux1 = n4 % 10;
            int aux2 = n4 / 10;
            n4 = aux1 + aux2;
        }
        if (n5 > 9)
        {
            int aux1 = n5 % 10;
            int aux2 = n5 / 10;
            n5 = aux1 + aux2;
        }
        if (n6 > 9)
        {
            int aux1 = n6 % 10;
            int aux2 = n6 / 10;
            n6 = aux1 + aux2;
        }
        if (n7 > 9)
        {
            int aux1 = n7 % 10;
            int aux2 = n7 / 10;
            n7 = aux1 + aux2;
        }
        if (n8 > 9)
        {
            int aux1 = n8 % 10;
            int aux2 = n8 / 10;
            n8 = aux1 + aux2;
        }

        int soma1 = n1 + n2 + n3 + n4 + n5 + n6 + n7 + n8;
        int soma2 = soma1 + w1 + w2 + w3 + w4 + w5 + w6 + w7 + w8;
        if (soma2 % 10 == 0 && (number >= 4000000000000000 && number <= 4999999999999999))
        {
            printf("VISA\n");
            return;
        }
        else if (soma2 % 10 == 0 && (number >= 5100000000000000 && number <= 5599999999999999))
        {
            printf("MASTERCARD\n");
            return;
        }
        else
        {
            printf("INVALID\n");
            return;
        }
    }
    // 13 digits
    else if (number >= 4000000000000 && number <= 4999999999999)
    {
        long long int aux = number;
        long long n1 = aux % 100 / 10 * 2;
        long long n2 = aux % 10000 / 1000 * 2;
        long long n3 = aux % 1000000 / 100000 * 2;
        long long n4 = aux % 100000000 / 10000000 * 2;
        long long n5 = aux % 10000000000 / 1000000000 * 2;
        long long n6 = aux % 1000000000000 / 100000000000 * 2;

        long long w1 = aux % 10;
        long long w2 = aux % 1000 / 100;
        long long w3 = aux % 100000 / 10000;
        long long w4 = aux % 10000000 / 1000000;
        long long w5 = aux % 1000000000 / 100000000;
        long long w6 = aux % 100000000000 / 10000000000;
        long long w7 = aux / 1000000000000;

        if (n1 > 9)
        {
            int aux1 = n1 % 10;
            int aux2 = n1 / 10;
            n1 = aux1 + aux2;
        }
        if (n2 > 9)
        {
            int aux1 = n2 % 10;
            int aux2 = n2 / 10;
            n2 = aux1 + aux2;
        }
        if (n3 > 9)
        {
            int aux1 = n3 % 10;
            int aux2 = n3 / 10;
            n3 = aux1 + aux2;
        }
        if (n4 > 9)
        {
            int aux1 = n4 % 10;
            int aux2 = n4 / 10;
            n4 = aux1 + aux2;
        }
        if (n5 > 9)
        {
            int aux1 = n5 % 10;
            int aux2 = n5 / 10;
            n5 = aux1 + aux2;
        }
        if (n6 > 9)
        {
            int aux1 = n6 % 10;
            int aux2 = n6 / 10;
            n6 = aux1 + aux2;
        }

        int soma1 = n1 + n2 + n3 + n4 + n5 + n6;
        int soma2 = soma1 + w1 + w2 + w3 + w4 + w5 + w6 + w7;
        if (soma2 % 10 == 0)
        {
            printf("VISA\n");
            return;
        }
        else
        {
            printf("INVALID\n");
            return;
        }
    }
    // 15 digits
    else if ((number >= 340000000000000 && number <= 349999999999999) ||
             (number >= 370000000000000 && number <= 379999999999999))
    {
        long long int aux = number;
        long long n1 = aux % 100 / 10 * 2;
        long long n2 = aux % 10000 / 1000 * 2;
        long long n3 = aux % 1000000 / 100000 * 2;
        long long n4 = aux % 100000000 / 10000000 * 2;
        long long n5 = aux % 10000000000 / 1000000000 * 2;
        long long n6 = aux % 1000000000000 / 100000000000 * 2;
        long long n7 = aux % 100000000000000 / 10000000000000 * 2;

        long long w1 = aux % 10;
        long long w2 = aux % 1000 / 100;
        long long w3 = aux % 100000 / 10000;
        long long w4 = aux % 10000000 / 1000000;
        long long w5 = aux % 1000000000 / 100000000;
        long long w6 = aux % 100000000000 / 10000000000;
        long long w7 = aux % 10000000000000 / 1000000000000;
        long long w8 = aux / 100000000000000;

        if (n1 > 9)
        {
            int aux1 = n1 % 10;
            int aux2 = n1 / 10;
            n1 = aux1 + aux2;
        }
        if (n2 > 9)
        {
            int aux1 = n2 % 10;
            int aux2 = n2 / 10;
            n2 = aux1 + aux2;
        }
        if (n3 > 9)
        {
            int aux1 = n3 % 10;
            int aux2 = n3 / 10;
            n3 = aux1 + aux2;
        }
        if (n4 > 9)
        {
            int aux1 = n4 % 10;
            int aux2 = n4 / 10;
            n4 = aux1 + aux2;
        }
        if (n5 > 9)
        {
            int aux1 = n5 % 10;
            int aux2 = n5 / 10;
            n5 = aux1 + aux2;
        }
        if (n6 > 9)
        {
            int aux1 = n6 % 10;
            int aux2 = n6 / 10;
            n6 = aux1 + aux2;
        }
        if (n7 > 9)
        {
            int aux1 = n7 % 10;
            int aux2 = n7 / 10;
            n7 = aux1 + aux2;
        }

        int soma1 = n1 + n2 + n3 + n4 + n5 + n6 + n7;
        int soma2 = soma1 + w1 + w2 + w3 + w4 + w5 + w6 + w7 + w8;
        if (soma2 % 10 == 0)
        {
            printf("AMEX\n");
            return;
        }
        else
        {
            printf("INVALID\n");
            return;
        }
    }
    else
    {
        printf("INVALID\n");
        return;
    }
}
