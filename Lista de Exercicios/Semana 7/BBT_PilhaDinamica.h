#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sPrato
{
    char cor[16];
    float tamanho;
    char tipo[16];
} prato;
typedef struct sNode
{
    prato info;
    struct sNode *prox;
} node;
void inicPilha(node **pilha)
{
    *pilha = NULL;
}
node *alocarNode()
{
    return (node *)malloc(sizeof(node));
}
void desalocarNode(node *q)
{
    free(q);
}
int vaziaPilha(node **pilha)
{
    if (*pilha == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void empilhar(node **pilha, prato elem)
{
    node *novo;
    novo = alocarNode();
    if (novo != NULL)
    {
        strcpy(novo->info.cor, elem.cor);
        strcpy(novo->info.tipo, elem.tipo);
        novo->info.tamanho = elem.tamanho;
        novo->prox = *pilha;
        *pilha = novo;
    }
    else
    {
        printf("Erro na alocacao de node.\n");
    }
}
void desempilhar(node **pilha)
{
    if (vaziaPilha(pilha) == 1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        *pilha = (*pilha)->prox;
    }
}
prato retornarTopo(node *pilha)
{
    if (vaziaPilha(&pilha) == 1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        return pilha->info;
    }
}
void printPrato(prato q)
{
    printf("Cor: %s.\nTamanho: %2.f.\nTipo: %s.\n", q.cor, q.tamanho, q.tipo);
}
void printPilha(node **pilha)
{
    node *aux;
    aux = *pilha;
    if (vaziaPilha(pilha) == 1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        while (aux)
        {
            printPrato(aux->info);
            printf("\n");
            aux = aux->prox;
        }
    }
}