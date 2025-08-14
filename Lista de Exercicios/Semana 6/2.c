#include <stdio.h>
#include "BBT_LCSE1.h"
int main(void)
{
    nodeHeader *pLista;
    inicLista(&pLista);
    if (listaVazia(&pLista) == 1)
    {
        printf("A lista esta vazia. Quantidade de processos: %d.\n", pLista->processCount);
    }
    else
    {
        printf("A lista nao esta vazia. Quantidade de processos: %d.\n", pLista->processCount);
    }
    return 0;
}