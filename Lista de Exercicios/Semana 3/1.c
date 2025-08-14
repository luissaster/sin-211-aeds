#include <stdio.h>
#include <stdlib.h>
#include "disciplinas.h"
int main(void)
{
    int num;
    node *ptrLista;
    do
    {
        printf("0. Inicalizar a lista.\n");
        printf("1. Inserir uma nova disciplina.\n");
        printf("2. Remover uma disciplina.\n");
        printf("3. Exibir disciplinas com carga horaria maior que 60.\n");
        printf("4. Encerrar programa.\n");
        scanf("%d", &num);
        switch (num)
        {
        case 0: // inicializar a lista
            ptrLista = inicializar(ptrLista);
            if (ptrLista == NULL)
            {
                printf("Lista inicializada com sucesso.\n");
            }
            else
            {
                printf("Erro ao inicializar a lista.\n");
            }
            break;
        case 1: // inserir nova disciplina
            printf("teste\n");
            node *q;
            q = alocarNode();
            int isCorrect = 0;
            do
            {
                fflush(stdin);
                printf("Insira o codigo da disciplina (Ex.: SIN110):\n");
                gets(q->info.cod);
                printf("Insira o nome da disciplina (Ex.: Programacao):\n");
                gets(q->info.discNome);
                printf("Insira a quantidade de creditos da disciplina (Ex.: 4):\n");
                scanf("%d", &q->info.cred);
                printf("Insira a carga horaria da disciplina (Ex.: 60):\n");
                scanf("%d", &q->info.cargaHoraria);
                printf("As informacoes inseridas foram:\n");
                printf("Codigo: %s.\n", q->info.cod);
                printf("Nome: %s.\n", q->info.discNome);
                printf("Creditos: %d.\n", q->info.cred);
                printf("Carga Horaria: %d.\n", q->info.cargaHoraria);
                printf("As informacoes estao corretas? 0 - Nao/1 - Sim\n");
                scanf("%d", &isCorrect);
            } while (isCorrect != 1);
            printf("Informacoes adicionadas com sucesso.\nEndereco do node: %p.\n", q);
            break;
        case 2: // remover uma disciplina
            break;
        case 3: // exibir disciplinas com cargaHoraria > 60
            break;
        }
    } while (num != 4);
    return 0;
}