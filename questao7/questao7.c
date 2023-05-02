#include <stdio.h>

int main(void)
{
    int mat[50];
    int x;
    int *p = &x;
    

    p = mat + 1;
    p = mat++;
    p = ++mat;
    x = (*mat)++;

    return 0;
}