//procurando menor, maior e altura da arvore

#include <stdio.h>
#include <string.h>
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

int verifica_menor(No_ABB *arvore){
    if(arvore == NULL) 
        return -1;
    if(arvore->esquerda == NULL)
        return arvore->info;
    else
        verifica_menor(arvore->esquerda);
}

int verifica_maior(No_ABB *arvore){
    if(arvore == NULL)
        return -1;
    if(arvore->direita == NULL)
        return arvore->info;
    else
        verifica_maior(arvore->direita);
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

int main(){
    No_ABB *arvore = NULL;
    int n;
    int inserido;
    int menor;
    int maior;
    int altura;

    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &inserido);
        Insere_arvore_recursiva(&arvore, inserido);
    }

    menor = verifica_menor(arvore);
    if(menor != -1)
        printf("menor valor: ['%d']\n", menor);

    maior = verifica_maior(arvore);
    if(maior != -1)
        printf("maior valor: ['%d']\n", maior);

    altura = altura_arvore(arvore);
    if(altura != -1)
        printf("Altura da arvore: %d\n", altura);
    return 0;
}