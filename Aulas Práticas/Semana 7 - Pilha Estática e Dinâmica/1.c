#include <stdio.h>
#include "BBT_PilhaEstatica.h"
int main(void)
{
    pilha p;
    inicPilha(&p);
    int op;
    float elem;
    do
    {
        printf("\n1. Empilhar\n2. Desempilhar\n3. Exibir pilha\n0. Encerrar\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Insira o elemento que deseja empilhar: ");
            scanf("%f", &elem);
            empilhar(&p, elem);
            break;
        case 2:
            desempilhar(&p);
            break;
        case 3:
            printPilha(&p);
            break;
        case 0:
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (op != 0);
    return 0;
}
