#include <stdio.h>
#include <string.h>
#include "playlist.h" //????????
int main(void)
{
    int choice;
    char name[32];
    song musicas[100];
    do
    {
        printf("Escolha qual acao:\n");
        printf("0. Inicializar playlist.\n");
        printf("1. Cadastrar musica.\n");
        printf("2. Pesquisar musica.\n");
        printf("3. Remover ultima musica.\n");
        printf("4. Mostrar playlist.\n");
        printf("5. Sair.\n");
        scanf("%d", &choice);
        //inicializar playlist
        if (choice == 0)
        {
            startPlaylist(&musicas);
        } 
        //cadastrar musica
        else if (choice == 1)
        {
            insertEnd(&musicas);
        }
        //pesquisar musica
        else if (choice == 2)
        {
            // perhaps um sistema de busca por autor?
            fflush(stdin);
            getchar();
            printf("Digite o nome da musica: ");
            gets(name);
            if (searchSong(&musicas, name) == -1)
            {
                printf("Musica nao encontrada.\n");
            }
            else
            {
                printf("Musica encontrada na posicao: %d.\n", searchSong(&musicas, name));
            }
        }
        //Remover musica
        else if (choice == 3)
        {
            removeEnd(&musicas);
        }
        //Print playlist
        else if (choice == 4)
        {
            printPlaylist(&musicas);
        }
    } while (choice != 5);
    return 0;
}