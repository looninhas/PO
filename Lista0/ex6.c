//Determine se uma árvore é simétrica.

#include <stdio.h>
#include <stdlib.h>

struct no_ABB{
    int info;
    struct no_ABB *direita;
    struct no_ABB *esquerda;
};
typedef struct no_ABB No_ABB;

No_ABB *cria_noA(int info){
    No_ABB *novo = (No_ABB*) malloc(sizeof(No_ABB));
    if(novo != NULL){
        novo->info = info;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;    
}

void Insere_arvore_recursiva(No_ABB **arvore, int num){
    if(*arvore == NULL) 
        *arvore = cria_noA(num);
    else if((*arvore)->info > num && (*arvore)->esquerda == NULL)
        (*arvore)->esquerda = cria_noA(num);
    else if((*arvore)->info < num && (*arvore)->direita == NULL)
        (*arvore)->direita = cria_noA(num);
    else if((*arvore)->info > num)
        Insere_arvore_recursiva(&(*arvore)->esquerda, num);
    else if((*arvore)->info < num)
        Insere_arvore_recursiva(&(*arvore)->direita, num);
}



int main(){

    return 0;
}