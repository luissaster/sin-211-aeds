#include <stdio.h>
#include <stdlib.h>
typedef struct sNode
{
    char info;
    struct sNode *dir;
    struct sNode *esq;
} node;
void inicLista(node **lista)
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
void inserirInicio(node **lista, char elem)
{
    node *novo;
    novo = alocarNode();
    if (novo != NULL)
    {
        novo->info = elem;
        novo->esq = NULL;
        novo->dir = *lista;
        if (vaziaLista(lista) == 0)
            (*lista)->esq = novo;
        *lista = novo;
    }
    else
    {
        printf("Erro na alocacao de no.\n");
    }
}
void imprimirLista(node **lista)
{
    node *q;
    q = *lista;
    if (vaziaLista(lista) != 1)
    {
        while (q->dir != NULL)
        {
            printf("%c / ", q->info);
            q = q->dir;
        }
        printf("%c.\n", q->info);
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}
node *pesquisar(node **lista, char elem)
{
    node *aux;
    aux = *lista;
    if (vaziaLista(lista) != 1)
    {
        while (aux != NULL)
        {
            if (aux->info == elem)
            {
                return aux;
            }
            aux = aux->dir;
        }
    }
    return NULL;
}
void removerInicio(node **lista)
{
    node *q;
    q = *lista;
    if (vaziaLista(lista) == 0)
    { // há itens na lista
        *lista = q->dir;
        if (*lista != NULL)
            (*lista)->esq = NULL;
        desalocarNode(q);
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}
void removerValor(node **lista, char elem)
{
    node *q;
    if ((q = pesquisar(lista, elem)) != NULL)
    {
        if (*lista == q)
        {
            removerInicio(lista);
        }
        else
        {
            (q->esq)->dir = q->dir;
            if (q->dir != NULL)
            {
                (q->dir)->esq = q->esq;
            }
            desalocarNode(q);
        }
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}
