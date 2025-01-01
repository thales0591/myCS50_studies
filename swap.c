#include <stdio.h>

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 50;
    printf("a is %i, b is %i\n", a, b);
    swap(&a, &b);
    printf("a is %i, b is %i\n", a, b);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}