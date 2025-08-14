#include <stdio.h>
#include <string.h>
typedef struct sDuracao
{
    int minutes, seconds;
} songTime;
typedef struct sPlaylist
{
    char songName[32], singerName[18];
    songTime songPlayTime;
    int n;
} song;
void startPlaylist(song *p)
{
    p->n = -1;
    int i;
    for (i = 0; i < 100; i++)
    {
        strcpy(p[i].songName, " ");
        strcpy(p[i].singerName, " ");
        p[i].songPlayTime.minutes = 0;
        p[i].songPlayTime.seconds = 0;
    }
    printf("Playlist limpa e inicializada!.\n");
}
void insertEnd(song *p)
{
    // getchar();
    fflush(stdin);
    p->n = p->n + 1;
    printf("n = %d.\n", p->n);
    printf("Insira o nome da musica: ");
    gets(p[p->n].songName);
    printf("Insira quantos minutos a musica dura: ");
    scanf("%d", &p[p->n].songPlayTime.minutes);
    printf("E quantos segundos: ");
    scanf("%d", &p[p->n].songPlayTime.seconds);
    printf("A musica tem uma duracao de %d:%d.\n", p[p->n].songPlayTime.minutes, p[p->n].songPlayTime.seconds);
    printf("Quem e o autor dessa musica?\n");
    // getchar();
    fflush(stdin);
    gets(p[p->n].singerName);
    printf("Musica cadastrada na posicao %d.\n", p->n);
}
int searchSong(song *p, char name[32])
{
    int i, hasFound = 0;
    for (i = 0; i < 100; i++)
    {
        if (strcmp(p[i].songName, name) == 0)
        {
            hasFound++;
            return i;
        }
        else
        {
            continue;
        }
    }
    if (hasFound == 0)
    {
        return -1;
    }
}
void removeEnd(song *p)
{
    strcpy(p[p->n].songName, " ");
    strcpy(p[p->n].singerName, " ");
    p[p->n].songPlayTime.minutes = 0;
    p[p->n].songPlayTime.seconds = 0;
    p->n = p->n - 1;
    printf("N = %d.\n", p->n);
}
void printPlaylist(song *p)
{
    int i;
    printf("--------------PLAYLIST FODA--------------\n");
    for (i = 0; i < 100; i++)
    {
        printf("%d. %s - %s. %d:%d.\n", i, p[i].songName, p[i].singerName, p[i].songPlayTime.minutes, p[i].songPlayTime.seconds);
    }
}