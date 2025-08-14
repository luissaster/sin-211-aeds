#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sBook
{
    char title[32];
    int pageCount;
} book;
typedef struct sNode
{
    book info;
    struct sNode *next;
} node;
void startStack(node **stack)
{
    *stack = NULL;
}
int isStackEmpty(node **stack)
{
    if (*stack == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
node *allocNode()
{
    return (node *)malloc(sizeof(node));
}
void deallocNode(node *q)
{
    free(q);
}
void push(node **stack, book insert)
{
    node *new;
    new = allocNode();
    if (new)
    {
        new->info = insert;
        new->next = *stack;
        *stack = new;
    }
    else
    {
        printf("Erro na alocacao de no.\n");
    }
}
node *pop(node **stack)
{
    node *aux;
    aux = *stack;
    if (isStackEmpty(stack) == 1)
    {
        printf("A pilha esta vazia.\n");
        return NULL;
    }
    else
    {
        *stack = (*stack)->next;
        return aux;
    }
}
void printBook(book q)
{
    printf("Titulo: %s.\nQuantidade de paginas: %d.\n", q.title, q.pageCount);
}
void printStack(node **stack)
{
    node *aux;
    aux = *stack;
    if (isStackEmpty(stack) == 1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        while (aux)
        {
            printBook(aux->info);
            printf("\n");
            aux = aux->next;
        }
    }
}