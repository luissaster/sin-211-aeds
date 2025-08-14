#include <stdio.h>
#include <stdlib.h>
#include "pratica4.h"
int main(void)
{
    node *pLista;
    int num = 0;
    inicLista(&pLista);
    do
    {
        printf("-------------------------------\n");
        printf("1. Inserir no inicio.\n");
        printf("2. Remover do inicio.\n");
        printf("3. Exibir elementos.\n");
        printf("0. Encerrar.\n");
        printf("-------------------------------\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            fflush(stdin);
            printf("Qual caractere deseja inserir?\n");
            char elem;
            scanf("%c", &elem);
            inserirInicio(&pLista, elem);
            break;
        case 2:
            removerInicio(&pLista);
            break;
        case 3:
            printLista(&pLista);
            printf("\n");
            break;
        }
    } while (num != 0);
    return 0;
}
