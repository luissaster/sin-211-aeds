#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sDisciplina
{
    char cod[7], discNome[32];
    int cred, cargaHoraria;
} disciplina;
typedef struct sNode
{
    disciplina info;
    struct sNode *prox;
} node;
node *inicializar(node *lista)
{
    lista = NULL;
    return lista;
}
node *alocarNode()
{
    return (node *)malloc(sizeof(node));
}
int listaVazia(node *lista)
{
    if (lista->prox = NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
node *inserirFim(node *lista, node elem)
{
    node *novo;
    node *aux;
    novo = alocarNode();
    if (novo != NULL)
    {
        strcpy(novo->info.cod, elem.info.cod);
        strcpy(novo->info.discNome, elem.info.discNome);
        novo->info.cred = elem.info.cred;
        novo->info.cargaHoraria = elem.info.cargaHoraria;
        novo->prox = NULL;
        if (listaVazia(lista))
        {
            lista = novo;
        }
        else
        {
            aux = lista;
            while (aux->prox != NULL)
            {
                aux = aux->prox;
            }
            aux->prox = novo;
        }
        return lista;
    }
    else
    {
        printf("Erro.\n");
        return NULL;
    }
}
void deletarNode(node *q)
{
}