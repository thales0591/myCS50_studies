#include <stdio.h>

int main(void)
{
    long long int credit = 5122222222222;
    long long int aux = credit;
    int valid = 0;
    int visa = 0;
    //visa - 16 digits
    if ( credit >= 4000000000000000 &&  credit <= 4999999999999999)
    {
        printf("visa");
        valid = 1;
        visa = 1;
    }
    //visa - 13 digits
    else if ( credit >= 4000000000000 &&  credit <= 4999999999999)
    {
        printf("visa");
        valid = 1;
        visa = 2;
    }
    //amex
    else if ( credit >= 340000000000000 &&  credit <= 349999999999999)
    {
        printf("amex");
        valid = 1;
    }
    else if ( credit >= 370000000000000 &&  credit <= 379999999999999)
    {
        printf("amex");
        valid = 1;
    }
    //mastercard
    else if ( credit >= 5100000000000000 &&  credit <= 5599999999999999)
    {
        printf("mastercard");
        valid = 1;
    }
    else
    {
        valid = 0;
    }
    if(valid)
    {
        if (visa == 1)
        {
            

        }
    }
}

int sixteen(long long int number) 
{   
    long long int aux = number;
    while(aux <= 100)
    {
        aux -= 100;
    }
    long int n1 = aux / 10;
    aux = number;
    while(aux <= 10000)
    {
        aux -= 10000;
    }
    long int n2 = aux / 1000;
    aux = number;
    while(aux <= 1000000)
    {
        aux -= 1000000;
    }
    long int n3 = aux / 100000;
    aux = number;
    while(aux <= 100000000)
    {
        aux -= 100000000;
    }
    long long int n4 = aux / 10000000;
    aux = number;
    while(aux <= 10000000000)
    {
        aux -= 10000000000;
    }
    long long int n5 = aux / 1000000000;
    aux = number;
    while(aux <= 1000000000000)
    {
        aux -= 1000000000000;
    }
    long long int n6 = aux / 100000000000;
    aux = number;
    while(aux <= 100000000000000)
    {
        aux -= 100000000000000;
    }
    long long int n7 = aux / 10000000000000;
}