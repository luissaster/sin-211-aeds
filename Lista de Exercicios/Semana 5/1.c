#include <stdio.h>
#include "BBT_LDE.h"
int main(void)
{

    int op;
    node *pLista;
    float elem;
    inicLista(&pLista);
    do
    {
        printf("\n-----------------MENU-----------------\n");
        printf("1. Inserir elemento no final da lista.\n");
        printf("2. Remover elemento no final da lista.\n");
        printf("3. Exibir a lista.\n");
        printf("4. Exibir a lista em ordem inversa.\n");
        printf("5. Exibir a soma de todos os elementos da lista.\n");
        printf("0. Sair.\n");
        printf("--------------------------------------\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Insira um numero real: ");
            scanf("%f", &elem);
            inserirFim(&pLista, elem);
            printf("Valor inserido com sucesso!\n");
            break;
        case 2:
            removerFim(&pLista);
            printf("Ultimo elemento removido com sucesso!\n");
            break;
        case 3:
            printf("Lista: ");
            imprimirLista(&pLista);
            break;
        case 4:
            printf("Lista invertida: ");
            imprimirListaInverso(&pLista);
            break;
        case 5:
            printf("A soma dos elementos da lista resulta em: %.2f.\n", somarLista(&pLista));
            break;
        case 0:
            printf("Ate mais!\n");
            break;
        default:
            printf("Opcao invalida, tente novamente.\n");
            break;
        }
    } while (op != 0);
    return 0;
}