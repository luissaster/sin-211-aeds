#include <stdio.h>
#include <stdlib.h>
typedef struct sProcesso
{
    char nome[64];
    int num;
} processo;
typedef struct sNode
{
    processo info;
    struct sNode *prox;
} node;
typedef struct sNodeHeader
{
    int processCount;
    node *l;
} nodeHeader;
void inicLista(nodeHeader **lista)
{
    (*lista)->l = NULL;
    (*lista)->processCount = 0;
}
int listaVazia(nodeHeader **lista)
{
    if ((*lista)->processCount == 0)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0; // lista nao esta vazia
    }
}