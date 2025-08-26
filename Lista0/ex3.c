//escrevendo niveis e total que a arvore abb suporta
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct no_ABB{
    int info;
    int nivel;
    struct no_ABB *direita;
    struct no_ABB *esquerda;
};
typedef struct no_ABB No_ABB;

No_ABB *cria_noA(int info, int nivel){
    No_ABB *novo = (No_ABB*) malloc(sizeof(No_ABB));
    if(novo != NULL){
        novo->info = info;
        novo->nivel = nivel;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;    
}

void Insere_arvore_recursiva(No_ABB **arvore, int num){
    if(*arvore == NULL) 
        *arvore = cria_noA(num, 0);
    else if((*arvore)->info > num && (*arvore)->esquerda == NULL)
        (*arvore)->esquerda = cria_noA(num, ((*arvore)->nivel + 1));
    else if((*arvore)->info < num && (*arvore)->direita == NULL)
        (*arvore)->direita = cria_noA(num, ((*arvore)->nivel +1));
    else if((*arvore)->info > num)
        Insere_arvore_recursiva(&(*arvore)->esquerda, num);
    else if((*arvore)->info < num)
        Insere_arvore_recursiva(&(*arvore)->direita, num);
}

int altura_arvore(No_ABB *arvore){
    if(arvore == NULL)
        return -1;
    else{
        int altura_direita = altura_arvore(arvore->direita);
        int altura_esquerda = altura_arvore(arvore->esquerda);
        if(altura_direita > altura_esquerda)
            return altura_direita + 1;
        else
            return altura_esquerda + 1;
    }
}

void em_ordem(No_ABB *arvore){
    if(arvore != NULL){
        em_ordem(arvore->esquerda);
        printf("[%d;%d]", arvore->info, arvore->nivel);
        em_ordem(arvore->direita);
    }
}



int main(){
    No_ABB *arvore = NULL;
    int altura = 0;

    Insere_arvore_recursiva(&arvore, 4);
    Insere_arvore_recursiva(&arvore, 2);
    Insere_arvore_recursiva(&arvore, 7);
    Insere_arvore_recursiva(&arvore, 10);
    Insere_arvore_recursiva(&arvore, 25);
    Insere_arvore_recursiva(&arvore, 14);
    Insere_arvore_recursiva(&arvore, 19);
    em_ordem(arvore);
    altura = altura_arvore(arvore);
    printf("\n");
    if(altura != -1){
        printf("Altura: %d\n", altura);
        printf("Para arvore ser estrita: %.0lf\n", pow(2, altura));
    }

    return 0;
}