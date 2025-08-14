#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int *x, *y;
    x = (int *)calloc(2, sizeof(int));
    y = x; //ponteiro y recebe o mesmo endereco de x
    if (x != NULL)
    {
        *x = 27; // x=27, y=27
        *y = 32; // x=32, y=32
        printf("Ponteiro X: %p.\n", x);
        printf("Ponteiro Y: %p.\n", y);
        printf("Valor do ponteiro X: %d.\n", *x);
        printf("Valor do ponteiro Y: %d.\n", *y);
        free(x);
    }
    return 0;
}