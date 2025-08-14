#include <stdio.h>
#include <stdlib.h>
#define TAMP 26
typedef struct sPilha
{
    char itens[TAMP];
    int topo;
} pilha;
void inicPilha(pilha *p)
{
    p->topo = -1;
}
int vaziaPilha(pilha *p)
{
    if (p->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int cheiaPilha(pilha *p)
{
    if (p->topo == TAMP - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void empilhar(pilha *p, char elem)
{
    if (cheiaPilha(p) == 1)
    {
        printf("A pilha esta cheia.\n");
    }
    else
    {
        p->topo++;
        p->itens[p->topo] = elem;
    }
}
char desempilhar(pilha *p)
{
    char q;
    if (vaziaPilha(p) == 1)
    {
        printf("A pilha esta vazia.\n");
        return -1;
    }
    else
    {
        q = p->itens[p->topo];
        p->topo--;
        return q;
    }
}
int retornarTopo(pilha *p)
{
    if (vaziaPilha(p) == 1)
    {
        printf("A pilha esta vazia.\n");
        return -1;
    }
    else
    {
        return p->topo;
    }
}
void printPilha(pilha *p)
{
    pilha q;
    q = *p;
    int i;
    if (vaziaPilha(&q) == 1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        for (i = q.topo; i > -1; i--)
        {
            printf("%c / ", desempilhar(&q));
        }
        printf("\n %d", q.topo);
    }
    /*int i;
    if (vaziaPilha(p) == 1)
    {
        printf("A pilha esta vazia.\n");
    }
    else
    {
        for (i = p->topo; i > -1; i--)
        {
            printf("%c / ", p->itens[i]);
        }
    }
    */
}