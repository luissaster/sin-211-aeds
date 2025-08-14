#include <stdio.h>
#include "BBT_LCSE.h"
int main(void)
{
    int op;
    node *pLista;
    char elem;
    inicList(&pLista);
    do
    {
        printf("1. Inserir caractere no inicio da lista.\n");
        printf("2. Remover elemento do final da lista.\n");
        printf("3. Exibir lista.\n");
        printf("4. Exibir vogais da lista.\n");
        printf("0. Encerrar.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Qual caractere deseja inserir?\n");
            scanf("%c", &elem);
            inserirInicio(&pLista, elem);
            printf("Caractere inserido com sucesso!\n");
            break;
        case 2:
            removerFinal(&pLista);
            break;
        case 3:
            imprimirLista(pLista);
            break;
        case 4:
            imprimirListaVogais(pLista);
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