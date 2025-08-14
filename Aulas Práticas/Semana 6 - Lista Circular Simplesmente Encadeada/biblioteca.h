#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sDias
{
    char diaSemana[13];
} dia;
typedef struct sNode
{
    dia info;
    struct sNode *prox;
} node;
void inicList(node **lista)
{
    *lista = NULL;
}
node *alocarNode()
{
    return (node *)malloc(sizeof(node));
}
void desalocarNode(node *q)
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
void inserirFinal(node **lista, char elem[13])
{
    node *novo;
    novo = alocarNode();
    if (novo != NULL)
    {
        strcpy(novo->info.diaSemana, elem);
        if (vaziaLista(lista) == 1)
        {
            *lista = novo;
            novo->prox = *lista;
        }
        else
        {
            novo->prox = (*lista)->prox;
            (*lista)->prox = novo;
            *lista = novo;
        }
    }
    else
    {
        printf("Erro na alocacao de no.\n");
    }
}
void removerInicio(node **lista)
{
    node *aux;

    if (vaziaLista(lista) != 1)
    { // Há itens na lista
        if ((*lista) == (*lista)->prox)
        {
            desalocarNode(*lista);
            *lista = NULL;
        }
        else
        {
            aux = (*lista)->prox;
            (*lista)->prox = aux->prox;
            desalocarNode(aux);
        }
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}
void imprimirLista(node *lista)
{
    node *aux;

    if (lista != NULL)
    { // Há itens na lista
        aux = lista->prox;
        do
        {
            printf("%s / ", aux->info.diaSemana);
            aux = aux->prox;
        } while (aux != lista->prox);
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
    printf("\n");
}