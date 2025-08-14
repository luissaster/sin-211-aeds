#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct sPerson
{
    char name[32], action[32]; // sacar, depositar, efetuar pagamento
} person;
typedef struct sNode
{
    person info;
    struct sNode *prox;
} node;
typedef struct sLine
{
    node *start, *end;
} line;
void initLine(line **q)
{
    (*q)->end = NULL;
    (*q)->start = NULL;
}
int isLineEmpty(line **q)
{
    if ((*q)->end == NULL && (*q)->start == NULL)
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
void queueIn(line **q, person p)
{
    node *newP;
    newP = allocNode();
    if (newP)
    {
        newP->info = p;
        newP->prox = NULL;
        if (isLineEmpty(q) == 1)
        {
            (*q)->start = newP;
            (*q)->end = newP;
        }
        else
        {
            ((*q)->end)->prox = newP;
            (*q)->end = newP;
            ((*q)->end)->prox = NULL;
        }
    }
    else
    {
        printf("Erro na alocacao de no.\n");
    }
}
void showPerson(person p)
{
    printf("Nome: %s.\n", p.name);
    printf("Acao: %s.\n", p.action);
}
void showLine(line *q)
{
    node *aux;
    aux = q->start;
    if (isLineEmpty(&q) == 1)
    {
        printf("A fila esta vazia.\n");
    }
    else
    {
        while (aux != NULL)
        {
            showPerson(aux->info);
            printf("-----------\n");
            aux = aux->prox;
        }
    }
}