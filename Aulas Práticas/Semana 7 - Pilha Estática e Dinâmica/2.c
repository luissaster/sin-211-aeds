#include <stdio.h>
#include <string.h>
#include "BBT_PilhaDinamica.h"
int main(void)
{
    book insert;
    int op;
    node *stack, *removed;
    startStack(&stack);
    do
    {
        printf("\n1. Inserir um livro no topo.\n2. Remover um livro do topo.\n3. Mostrar pilha de livros.\n0. Encerrar.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Insira o titulo do livro: ");
            gets(insert.title);
            printf("Insira a quantidade de paginas: ");
            scanf("%d", &insert.pageCount);
            push(&stack, insert);
            printf("Livro inserido\nTitulo: %s.\nPaginas: %d.\n", insert.title, insert.pageCount);
            break;
        case 2:
            removed = pop(&stack);
            if (removed)
            {
                printf("Livro removido\nTitulo: %s.\nPaginas: %d.\n", removed->info.title, removed->info.pageCount);
            }
            break;
        case 3:
            printStack(&stack);
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