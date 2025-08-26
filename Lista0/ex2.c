//verificando se duas arvores sao identicas

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

int verifica_igualdadeABB(No_ABB *arvore, No_ABB *arvore2){
    if(arvore == NULL && arvore2 == NULL)
        return 1;
    if(arvore == NULL || arvore2 == NULL)
        return 0;
    if(arvore->info == arvore2->info){ //anda pra verificar a igualdade
        return verifica_igualdadeABB(arvore->direita, arvore->direita) && verifica_igualdadeABB(arvore->esquerda, arvore2->esquerda);
    }
    else{
        return 0;
    }
    
}



int main(){
    No_ABB *arvore = NULL;
    No_ABB *arvore2 = NULL;
    int n;
    int inserido;

    printf("Quantidade a inserir na arvore 1: ");
    scanf("%d", &n);
    for(int i = 0 ; i < n; i++)
        scanf("%d", &inserido);
        Insere_arvore_recursiva(&arvore, inserido);
    

    printf("\nQuantidade a inserir na arvore 2: ");
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &inserido);
        Insere_arvore_recursiva(&arvore2, inserido);
    
    if(verifica_igualdadeABB(arvore, arvore2) != 0)
        printf("As arvores sao identicas\n");
    else
        printf("As arvores sao diferentes\n");
    return 0;
}