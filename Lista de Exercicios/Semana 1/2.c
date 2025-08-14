#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int sSize, i;
    char *p;
    printf("Qual o tamanho da string que deseja alocar?\n");
    scanf("%d", &sSize);
    p = (char *)calloc(sSize, sizeof(char));
    if (p != NULL)
    {
        fflush(stdin);
        printf("String alocada com sucesso.\n");
        printf("Digite o conteudo da string: ");
        gets(p);
        printf("A string inserida foi: %s.\n", p);
        printf("A string, sem suas vogais, fica: ");
        for (i = 0; i < sSize; i++)
        {
            if (p[i] != 'a' && p[i] != 'e' && p[i] != 'i' && p[i] != 'o' && p[i] != 'u' && p[i] != 'A' && p[i] != 'E' && p[i] != 'I' && p[i] != 'O' && p[i] != 'U')
            {
                printf("%c ", p[i]);
            }
        }
        free(p);
        p = NULL;
    }

    return 0;
}