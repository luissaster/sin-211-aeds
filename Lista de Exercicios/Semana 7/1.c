#include <stdio.h>
#include "BBT_PilhaEstatica.h"
int main(void)
{
    int op;
    char elem;
    pilha *p;
    inicPilha(p);
    do
    {
        printf("\n1. Inserir um elemento no topo da pilha.\n");
        printf("2. Remover um elemento do topo da pilha.\n");
        printf("3. Retornar o elemento que esta no topo da pilha sem remove-lo .\n");
        printf("4. Exibir todos os elementos da pilha.\n");
        printf("0. Encerrar.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Qual caractere deseja inserir no topo da pilha?\n");
            scanf("%c", &elem);
            empilhar(p, elem);
            break;
        case 2:
            printf("Elemento removido: %c.\n", desempilhar(p));
            break;
        case 3:
            printf("Posicao do topo: %d.\nElemento no topo: %c.\n", retornarTopo(p), p->itens[p->topo]);
            break;
        case 4:
            printPilha(p);
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