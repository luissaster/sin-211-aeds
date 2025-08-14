#include <stdio.h>
#include <string.h>
#include "BBT_PilhaDinamica.h"
int main(void)
{
    node *topo;
    prato novoPrato;
    int op, tipoOp = 0;
    inicPilha(&topo);
    printf("Bem vindo ao Empilhador de Prato 3000!\n");
    do
    {
        printf("\n1. Inserir elemento no topo da pilha.\n");
        printf("2. Remover elemento do topo da pilha.\n");
        printf("3. Retornar elemento no topo.\n");
        printf("4. Exibir pilha.\n");
        printf("0. Encerrar.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Informe a cor do prato: ");
            gets(novoPrato.cor);
            printf("Tipos de prato: \n1. Porcelana\n2. Plastico\n3. Vidro\nInsira o codigo do tipo do seu prato: ");
            fflush(stdin);
            scanf("%d", &tipoOp);
            if (tipoOp == 1)
            {
                strcpy(novoPrato.tipo, "Porcelana");
            }
            else if (tipoOp == 2)
            {
                strcpy(novoPrato.tipo, "Plastico");
            }
            else if (tipoOp == 3)
            {
                strcpy(novoPrato.tipo, "Vidro");
            }
            printf("Insira o tamanho do prato em numero real: ");
            scanf("%f", &novoPrato.tamanho);
            printf("O prato inserido tem as seguintes caracteristicas:\n");
            printf("Cor: %s.\n", novoPrato.cor);
            printf("Tipo: %s.\n", novoPrato.tipo);
            printf("Tamanho: %.2f.\n", novoPrato.tamanho);
            empilhar(&topo, novoPrato);
            printf("Prato empilhado com sucesso!\n");
            break;
        case 2:
            desempilhar(&topo);
            break;
        case 3:
            if (vaziaPilha(&topo) != 1)
            {
                printf("Prato no topo:\n");
                printf("Cor: %s.\n", retornarTopo(topo).cor);
                printf("Tipo: %s.\n", retornarTopo(topo).tipo);
                printf("Tamanho: %.2f.\n", retornarTopo(topo).tamanho);
            }
            else
            {
                retornarTopo(topo);
            }
            break;
        case 4:
            if (vaziaPilha(&topo) != 1)
            {
                printf("-------------PILHA-------------\n");
                printPilha(&topo);
                printf("--------------FIM--------------");
            }
            else
            {
                printPilha(&topo);
            }
            break;
        }
    } while (op != 0);
    return 0;
}