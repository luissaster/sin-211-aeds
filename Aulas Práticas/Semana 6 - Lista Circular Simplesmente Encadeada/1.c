#include <stdio.h>
#include "biblioteca.h"
int main(void)
{
    char diaSemana[13];
    int op;
    node *pLista;
    inicList(&pLista);
    do
    {
        printf("1. Inserir elemento no final da lista.\n");
        printf("2. Remover elemento do inicio da lista.\n");
        printf("3. Exibir os elementos da lista.\n");
        printf("0. Encerrar.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Qual dia deseja inserir? ");
            gets(diaSemana);
            inserirFinal(&pLista, diaSemana);
            break;
        case 2:
            removerInicio(&pLista);
            break;
        case 3:
            imprimirLista(pLista);
            break;
        case 0:
            printf("Ate mais!\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (op != 0);
    return 0;
}