#include <stdio.h>
#include <stdlib.h>
typedef struct sNode
{
    float info;
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
void inserirFim(node **lista, float elem)
{
    node *novo;
    node *aux;
    novo = alocarNode();
    if (novo != NULL)
    {
        novo->info = elem;
        novo->esq = NULL;
        novo->dir = NULL;
        if (vaziaLista(lista) == 1)
        {
            *lista = novo;
        }
        else
        {
            aux = *lista;
            while (aux->dir != NULL)
            {
                aux = aux->dir;
            }
            aux->dir = novo;
            novo->esq = aux;
        }
    }
    else
    {
        printf("Erro");
        exit(1);
    }
}
void removerFim(node **lista)
{
    node *aux;
    aux = *lista;
    if (vaziaLista(lista) == 1)
    {
        printf("A lista esta vazia.\n");
    }
    else
    {
        while (aux->dir != NULL)
        {
            aux = aux->dir;
        }
        if (aux->esq == NULL && aux->dir == NULL)
        { // o elemento e o unico na lista
            desalocarNode(aux);
            *lista = NULL;
        }
        else
        { // ha mais de um elemento na lista
            aux->esq->dir = NULL;
            aux->esq = NULL;
            desalocarNode(aux);
        }
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
            printf("%.2f / ", q->info);
            q = q->dir;
        }
        printf("%.2f.\n", q->info);
    }
    else
    {
        printf("A lista esta vazia.\n");
    }
}
void imprimirListaInverso(node **lista)
{
    node *q;
    q = *lista;
    if (vaziaLista(lista) == 1)
    {
        printf("A lista esta vazia.\n");
    }
    else
    {
        while (q->dir != NULL)
        {
            q = q->dir;
        }
        while (q->esq != NULL)
        {
            printf("%.2f / ", q->info);
            q = q->esq;
        }
        printf("%.2f.\n", q->info);
    }
}
float somarLista(node **lista)
{
    node *q;
    q = *lista;
    float soma = 0;
    if (vaziaLista(lista) == 1)
    {
        printf("A lista esta vazia.\n");
        return 0;
    }
    else
    {
        while (q->dir != NULL)
        {
            soma = soma + q->info;
            q = q->dir;
        }
        soma = soma + q->info;
        return soma;
    }
}