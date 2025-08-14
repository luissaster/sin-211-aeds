#include <stdio.h>
#include <stdlib.h>
typedef struct sNode
{
    char info;
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
void inserirInicio(node **lista, char elem)
{
    node *novo;
    novo = alocarNode();
    if (novo == NULL)
    {
        printf("Erro ao alocar no.\n");
    }
    else
    {
        novo->info = elem;
        if (*lista == NULL)
        { // nao ha elementos na lista
            *lista = novo;
            novo->prox = *lista;
        }
        else
        { // ha elementos na lista
            novo->prox = (*lista)->prox;
            (*lista)->prox = novo;
        }
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
            printf("%c ", aux->info);
            aux = aux->prox;
        } while (aux != lista->prox);
    }
    else
    {
        printf("\n Lista vazia !");
    }
    printf("\n");
}
void removerFinal(node **lista)
{
    node *aux;
    node *ant;
    ant = *lista;
    aux = *lista;
    if (vaziaLista(lista) == 1)
    {
        printf("A lista esta vazia.\n");
    }
    else
    {
        if (aux->prox == aux)
        {
            // ha apenas um elemento na lista
            desalocarNode(aux);
            *lista = NULL;
        }
        else
        {
            // ha mais de um elemento na lista
            while (ant->prox != *lista)
            {
                ant = ant->prox;
            }
            ant->prox = aux->prox;
            *lista = ant;
        }
    }
}
void imprimirListaVogais(node *lista)
{
    node *aux;
    if (lista != NULL)
    { // Há itens na lista
        aux = lista->prox;
        do
        {
            switch (aux->info)
            {
            case 'a':
                printf("%c ", aux->info);
                break;
            case 'A':
                printf("%c ", aux->info);
                break;
            case 'e':
                printf("%c ", aux->info);
                break;
            case 'E':
                printf("%c ", aux->info);
                break;
            case 'i':
                printf("%c ", aux->info);
                break;
            case 'I':
                printf("%c ", aux->info);
                break;
            case 'o':
                printf("%c ", aux->info);
                break;
            case 'O':
                printf("%c ", aux->info);
                break;
            case 'u':
                printf("%c ", aux->info);
                break;
            case 'U':
                printf("%c ", aux->info);
                break;
            }
            aux = aux->prox;
        } while (aux != lista->prox);
    }
    else
    {
        printf("\n Lista vazia !");
    }
    printf("\n");
}