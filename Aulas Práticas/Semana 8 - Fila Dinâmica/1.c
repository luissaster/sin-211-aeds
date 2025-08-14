#include <stdio.h>
#include <string.h>
#include "BBT_FilaDinamica.h"
int main(void)
{
    line *pLine;
    int op, lineAction;
    person insert;
    pLine = (line *)malloc(sizeof(line));
    initLine(&pLine);
    do
    {
        printf("\n1. Inserir uma pessoa na fila.\n2. Exibir a fila.\n0. Sair.\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            fflush(stdin);
            printf("Insira o nome: ");
            gets(insert.name);
            printf("Escolha a acao:\n1. Sacar\n2. Depositar\n3. Efetuar pagamento.\n");
            scanf("%d", &lineAction);
            switch (lineAction)
            {
            case 1:
                strcpy(insert.action, "Sacar");
                break;
            case 2:
                strcpy(insert.action, "Depositar");
                break;
            case 3:
                strcpy(insert.action, "Efetuar pagamento");
                break;
            default:
                printf("Opcao invalida.\n");
                break;
            }
            queueIn(&pLine, insert);
            printf("Pessoa inserida com sucesso.\n");
            break;
        case 2:
            showLine(pLine);
            break;
        }
    } while (op != 0);
    return 0;
}