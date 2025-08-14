#include <stdio.h>
#include <stdlib.h>
typedef struct sNode
{
    char info;
    struct sNode *prox;
} node;
void inicLista(node **lista)
{
    *lista = NULL;
}
node *alocNode()
{
    return (node *)malloc(sizeof(node));
}
void desalocNode(node *q)
{
    free(q);
}
int vaziaLista(node **lista)
{
    if (*lista == NULL)
    {
        return 1;
    }
    return 0;
}
void inserirInicio(node **lista, int elem)
{
    node *novo;
    novo = alocNode();
    if (novo != NULL)
    {
        novo->info = elem;
        novo->prox = *lista;
        *lista = novo;
    }
    else
    {
        printf("\nERRO na alocacao do no.");
    }
}
void removerInicio(node **lista)
{
    node *q;
    q = *lista;
    if (vaziaLista(lista) == 0)
    {
        *lista = q->prox;
        desalocNode(q);
    }
    else
    {
        printf("\nERRO: lista vazia. \n");
    }
}
void inserirFim(node **lista, int elem)
{
    node *novo;
    node *aux;
    novo = alocNode();
    if (novo != NULL)
    {
        novo->info = elem;
        novo->prox = NULL;
        if (vaziaLista(lista))
            *lista = novo;
        else
        {
            aux = *lista;
            while (aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    else
    {
        printf("\nErro na alocacao do no");
    }
}
void printLista(node **lista)
{
    node *aux;
    aux = *lista;
    if (vaziaLista(lista))
    {
        printf("A lista esta vazia.\n");
    }
    while (aux != NULL)
    {
        printf("%c ", aux->info);
        aux = aux->prox;
    }
}
