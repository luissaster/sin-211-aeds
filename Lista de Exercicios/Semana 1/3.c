#include <stdio.h>

int main(void)
{
    char string[64];
    int i;
    for (i = 0; i < 64; i++)
    {
        string[i] = ' ';
    }
    printf("Qual string deseja inserir?\n");
    gets(string);
    printf("A string inserida foi: %s.\n", string);
    printf("Essa string ficara assim sem suas vogais:\n");
    for (i = 0; i < 64; i++)
    {
        if (string[i] != 'a' && string[i] != 'e' && string[i] != 'i' && string[i] != 'o' && string[i] != 'u' && string[i] != 'A' && string[i] != 'E' && string[i] != 'I' && string[i] != 'O' && string[i] != 'U')
        {
            printf("%c ", string[i]);
        }
    }

    return 0;
}