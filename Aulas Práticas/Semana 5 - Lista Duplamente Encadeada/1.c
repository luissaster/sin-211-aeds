#include <stdio.h>
#include "biblioteca.h"
int main(void)
{
    int op;
    char elem;
    node *pLista;
    inicLista(&pLista);
    do
    {
        printf("1. Inserir elemento no inicio da lista.\n");
        printf("2. Remover determinado elemento da lista.\n");
        printf("3. Exibir elementos da lista.\n");
        printf("0. Sair.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Insira um caractere: ");
            scanf("%c", &elem);
            inserirInicio(&pLista, elem);
            printf("Caractere inserido com sucesso.\n");
            break;
        case 2:
            fflush(stdin);
            printf("Insira o caractere que deseja remover: ");
            scanf("%c", &elem);
            removerValor(&pLista, elem);
            break;
        case 3:
            imprimirLista(&pLista);
            break;
        case 0:
            printf("Ate mais!.\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
        }
    } while (op != 0);
    return 0;
}