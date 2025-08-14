#include "BBT_ListaDinamicaS04.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int choice;
    char nome[64];
    node *pLista;
    inicLista(&pLista);
    do
    {
        printf("1. Inserir novo contato.\n");
        printf("2. Remover contato.\n");
        printf("3. Pesquisar (Mover para frente).\n");
        printf("4. Pesquisar (Transposicao).\n");
        printf("5. Pesquisar (Contagem).\n");
        printf("6. Exibir lista de contatos.\n");
        printf("0. Sair.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            fflush(stdin);
            contato novo;
            printf("Insira o nome do contato: ");
            gets(novo.nome);
            fflush(stdin);
            printf("Insira o numero do contato (Ex.: 34998223460): ");
            gets(novo.numero);
            inserirOrdenado(&pLista, novo);
            break;
        case 2:
            fflush(stdin);
            printf("Digite o numero do contato que deseja remover: ");
            char num[64];
            gets(num);
            removerContato(&pLista, num);
            break;
        case 3:
            fflush(stdin);
            printf("Digite o nome do contato que deseja pesquisar: ");
            gets(nome);
            pesquisaParaFrente(&pLista, nome);
            break;
        case 4:
            fflush(stdin);
            printf("Digite o nome do contato que deseja pesquisar: ");
            gets(nome);
            pesquisaTransposicao(&pLista, nome);
            break;
        case 5:
        fflush(stdin);
        printf("Digite o nome do contato que deseja pesquisar: ");
        gets(nome);
        pesquisaContagem(&pLista, nome);
        break;
        case 6:
            imprimirLista(&pLista);
            break;
        }
    } while (choice != 0);
}