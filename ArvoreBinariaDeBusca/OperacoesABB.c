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

No_ABB *Insere_arvore(No_ABB *arvore, int num){
    No_ABB *novo = cria_noA(num);
    if(arvore == NULL)
        arvore = cria_noA(num);
    else{
        No_ABB *aux = arvore;
        No_ABB *aux2 = NULL;
        while(aux != NULL){
            aux2 = aux;
            if(aux->info > num) //menor anda pra esquerda
                aux = aux->esquerda;
            else //maior pra direita
                aux = aux->direita;
        }
        if(aux2->info > num)//se for maior bota na esquerda
            aux2->esquerda = novo;
        else if(aux2->info < num)
            aux2->direita = novo;
    }
    return arvore;

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

int consulta_arvore(No_ABB *arvore, int num){
    No_ABB *aux = arvore;
    int achado = 0;
    while(aux != NULL && achado == 0){
        if(aux->info < num)
            aux = aux->direita;
        else if(aux->info > num)
            aux = aux->esquerda;
        else if(aux->info == num)
            achado = 1;
    }
    return achado;
}

int consulta_arvore_recursiva(No_ABB *arvore, int num){
     if(arvore == NULL)
        return 0;
    if(arvore->info == num)
        return 1;
    if(arvore->info < num)
        return consulta_arvore_recursiva(arvore->direita, num);
    return consulta_arvore_recursiva(arvore->esquerda, num);
}

void em_ordem(No_ABB *arvore){
    if(arvore != NULL){
        em_ordem(arvore->esquerda);
        printf("[%d]", arvore->info);
        em_ordem(arvore->direita);
    }
}


int main(){
    No_ABB *arvore = NULL;
    int n;
    int inserido;
    printf("quantidade colocada na arvore:");
    scanf("%d", &n);
    for(int i=1; i<=n; i++){
        printf("quantidade a ser inserida na arvore:");
        scanf("%d", &inserido);
        Insere_arvore_recursiva(&arvore, inserido);
    }
    printf("arvore em ordem\n");
    em_ordem(arvore);

    printf("\nnumero a ser encontrado:");
    scanf("%d", &n);
    if(consulta_arvore_recursiva(arvore, n) == 1)
        printf("Numero encontrado\n");
    else
        printf("Numero nao encontrado\n");
    return 0;
}