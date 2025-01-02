#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int m;
    int *a;
    int *b = malloc(sizeof(int));
    a = &m;
    m = 4;
    *b = 5;
    printf("m is %i, a is %i, m is %i", m, *a, *b);
}