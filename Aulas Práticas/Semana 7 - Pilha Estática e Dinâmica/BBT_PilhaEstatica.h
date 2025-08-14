#include<stdio.h>
#define TAMP 50
typedef struct sPilha{
    float itens[TAMP];
    int topo;
}pilha;
void inicPilha(pilha* p){
    p->topo = -1;
}
int vaziaPilha(pilha *p){
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}
int cheiaPilha(pilha *p){
    if(p->topo == TAMP - 1){
        return 1;
    }else{
        return 0;
    }
}
void empilhar(pilha *p, float elem){
    if(cheiaPilha(p) == 1){
        printf("A pilha esta cheia.\n");
        return;
    }else{
        p->topo++;
        p->itens[p->topo] = elem;
    }
}
int desempilhar(pilha*p){
    int q;
    if(vaziaPilha(p) == 1){
        printf("A pilha esta vazia.\n");
        return -1;
    }else{
        q = p->itens[p->topo];
        p->topo--;
        return q;
    }
}
void printPilha(pilha *p){
    int i;
    if(vaziaPilha(p) == 1){
        printf("A pilha esta vazia.\n");
        return;
    }
    for(i=p->topo; i>-1; i--){
        printf("%.2f / ", p->itens[i]);
    }
}
