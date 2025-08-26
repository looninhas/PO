//verificando se a arvore eh 100% completa (2^n)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


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

int contando_nos(No_ABB *arvore){
    if(arvore == NULL)
        return 0;
    return contando_nos(arvore->direita) + contando_nos(arvore->esquerda) + 1;

}

int main(){
    No_ABB *arvore = NULL;
    Insere_arvore_recursiva(&arvore, 2);
    Insere_arvore_recursiva(&arvore, 1);
    Insere_arvore_recursiva(&arvore, 3);
    Insere_arvore_recursiva(&arvore, 23);

    int altura = altura_arvore(arvore);
    int somatorio_altura = 0;
    int nos = contando_nos(arvore);
    
    if((int)pow(2, altura+1)-1 == nos)
        printf("Arvore completa\n");
    else
        printf("Nao completa\n");

    return 0;
}