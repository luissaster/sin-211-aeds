#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sContato
{
    char nome[64], numero[64];
} contato;
typedef struct sNode
{
    contato info;
    int cont;
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
node *inserirOrdenado(node **lista, contato novoContavo)
{
    node *atual = *lista;
    node *anterior = NULL;
    node *novo;
    novo = alocNode();
    if (novo != NULL)
    {
        strcpy(novo->info.nome, novoContavo.nome);
        strcpy(novo->info.numero, novoContavo.numero);
        novo->cont = 0;
        while (atual != NULL && atual->info.nome[0] < novoContavo.nome[0])
        {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual == *lista)
        {
            novo->prox = *lista;
            *lista = novo;
        }
        else
        {
            anterior->prox = novo;
            novo->prox = atual;
        }
        return *lista;
    }
    else
    {
        printf("Erro na alocacao do node.\n");
        return NULL;
    }
}
void imprimirLista(node **lista)
{
    node *q;
    q = *lista;
    if (vaziaLista(lista) != 1)
    {
        while (q->prox != NULL)
        {
            printf("Nome: %s.\nNumero: %s.\n", q->info.nome, q->info.numero);
            q = q->prox;
        }
        printf("Nome: %s.\nNumero: %s.\n", q->info.nome, q->info.numero);
    }
    else
    {
        printf("Voce nao tem nenhum contato salvo.\n");
    }
}
void removerContato(node **lista, char *num)
{
    if (vaziaLista(lista) == 1)
    {
        printf("Voce nao tem nenhum contato salvo.\n");
    }
    else
    {
        node *aux, *prox, *ant;
        int n = 1;
        aux = *lista;
        prox = aux;
        ant = aux;
        if (strcmp(aux->info.numero, num) != 0)
        {
            while (strcmp(aux->info.numero, num) != 0 && aux->prox != NULL)
            {
                ant = aux;
                aux = aux->prox;
                prox = aux->prox;
            }
        }
        else
        {
            *lista = aux->prox;
            desalocNode(aux);
            printf("Contato removido.\n");
            n = 0;
        }
        if (n != 0)
        {
            if (strcmp(aux->info.numero, num) == 0)
            {
                ant->prox = prox;
                desalocNode(aux);
                printf("Contato removido.\n");
            }
            else
            {
                printf("Contato nao encontrado.\n");
            }
        }
    }
}
void pesquisaParaFrente(node **lista, char *nome)
{
    if (vaziaLista(lista) == 1)
    {
        printf("Voce nao tem nenhum contato salvo.\n");
    }
    else
    {
        node *aux, *ant, *prox, *res;
        int i = 0;
        aux = *lista;
        ant = *lista;
        res = *lista;
        while (strcmp(aux->info.nome, nome) != 0 && aux->prox != NULL)
        {
            ant = aux;
            aux = aux->prox;
            prox = aux->prox;
            i++;
        }
        if (strcmp(aux->info.nome, nome) == 0)
        {
            printf("Nome: %s.\nNumero: %s.\n", aux->info.nome, aux->info.numero);
            if (i != 0)
            {
                ant->prox = prox;
                *lista = aux;
                aux->prox = res;
            }
        }
        else
        {
            printf("Contato nao encontrado.\n");
        }
    }
}
void pesquisaTransposicao(node **lista, char *nome)
{
    node *aux, *prox, *ant;
    int i = 0, j;
    aux = *lista;
    ant = *lista;
    if (vaziaLista(lista) == 1)
    {
        printf("Voce nao tem nenhum contanto salvo.\n");
    }
    else
    {
        while (strcmp(aux->info.nome, nome) != 0 && aux->prox != NULL)
        {
            aux = aux->prox;
            prox = aux->prox;
            i++;
        }
        if (strcmp(aux->info.nome, nome) == 0)
        {
            printf("Nome: %s.\nNumero: %s.\n", aux->info.nome, aux->info.numero);
            if (i != 0)
            {
                if (i == 1)
                {
                    ant->prox = aux->prox;
                    aux->prox = ant;
                    *lista = aux;
                }
                else
                {
                    for (j = 0; j < i - 2; j++)
                    {
                        ant = ant->prox;
                    }
                    (ant->prox)->prox = aux->prox;
                    aux->prox = ant->prox;
                    ant->prox = aux;
                }
            }
        }
        else
        {
            printf("Contato nao encontrado.\n");
        }
    }
}
void pesquisaContagem(node **lista, char *nome)
{
    node *aux, *prox, *ant, *ref, *proxre;
    int i = 0, j = 0;
    aux = *lista;
    ant = *lista;
    ref = *lista;
    prox = *lista;
    if (vaziaLista(lista) == 1)
    {
        printf("Voce nao tem nenhum contato salvo.\n");
    }
    else
    {
        while (strcmp(aux->info.nome, nome) != 0 && aux->prox != NULL)
        {
            ant = aux;
            aux = aux->prox;
            prox = aux->prox;
            i++;
        }

        if (strcmp(aux->info.nome, nome) == 0)
        {
            printf("Nome: %s.\nNumero: %s.\n", aux->info.nome, aux->info.numero);
            aux->cont++;
            if (i != 0)
            {
                proxre = prox;
                while (ref->cont > aux->cont)
                {
                    ant = ref;
                    ref = ref->prox;
                    if (ref->prox == aux)
                    {
                        prox = (ref->prox)->prox;
                    }
                    else
                    {
                        prox = ref->prox;
                    }
                    j++;
                }
                if (j == 0)
                {
                    ant->prox = prox;
                    aux->prox = ref;
                    *lista = aux;
                }
                else
                {
                    ant->prox = aux;
                    aux->prox = ref;
                    ref->prox = prox;
                }
            }
        }
        else
        {
            printf("Contato nao encontrado\n");
        }
    }
}
