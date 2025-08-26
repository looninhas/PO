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

void Remove_valor_arvoreABB(No_ABB *arvore, int valor_removido){
    //procurando na arvore o valor
    No_ABB *pai = NULL;
    No_ABB *filho = arvore;
    int achado = 0;
    if(arvore != NULL){
        while(filho != NULL && achado == 0){
            if(filho->info == valor_removido) {
                achado = 1;
            }
            else {
                pai = filho;
                if(valor_removido > filho->info)
                    filho = filho->direita;
                else
                    filho = filho->esquerda;
            }
        }
        if(achado == 1) {
            if (pai == NULL) { // estamos na raiz
                printf("Caso que esta na raiz\n");
                pai = filho;
                No_ABB *aux = pai;
                if(filho->esquerda != NULL) { // procurando antecessor
                    printf("Entrei aqui 1\n");
                    pai = pai->esquerda;
                    while(pai->direita != NULL){
                        aux = pai;
                        pai = pai->direita;
                    }
                    filho->info = pai->info;
                    if(filho == aux){
                        filho->esquerda = NULL;
                    }
                    else
                        aux->direita = pai->esquerda;
                }else{//procurando sucessor
                    printf("Entrei aqui 2\n");
                    pai = pai->direita;
                    while(pai->esquerda != NULL){
                        aux = pai;
                        pai = pai->esquerda;
                    }
                    filho->info = pai->info;
                    if(filho == aux)
                        filho->direita = NULL;
                    else
                        aux->esquerda = pai->direita;
                } 
            } else if(pai->direita == NULL && pai->esquerda == NULL) //tirando a raiz quando a arvore é um só elemento
                arvore = NULL;
            else if(filho->direita == NULL && filho->esquerda != NULL || filho->direita != NULL && filho->esquerda == NULL){ // quando o filho so tem 1 no nele
                if(pai->direita == filho && filho->direita != NULL)
                    pai->direita = filho->direita;
                else if(pai->direita == filho && filho->esquerda != NULL)
                    pai->direita = filho->esquerda;
                else if(pai->esquerda == filho && filho->direita != NULL)
                    pai->esquerda = filho->direita;
                else if(pai->esquerda == filho && filho->esquerda != NULL)
                    pai->esquerda = filho->esquerda;
            }else if(filho->direita == NULL && filho->esquerda == NULL){
                if(pai->direita == filho)
                    pai->direita = NULL;
                else
                    pai->esquerda = NULL;
                free(filho);
            } else { // se o filho tiver 2 nos nele (atecessor)
                printf("Caso que possui 2 filhos\n");
                No_ABB *aux = pai;
                if(filho->esquerda != NULL) { // procurando antecessor
                    printf("Entrei aqui 1\n");
                    pai = pai->esquerda;
                    while(pai->direita != NULL){
                        aux = pai;
                        pai = pai->direita;
                    }
                    filho->info = pai->info;
                    aux->direita = pai->esquerda;
                }else{//procurando sucessor
                    printf("Entrei aqui 2\n");
                    pai = pai->direita;
                    while(pai->esquerda != NULL){
                        aux = pai;
                        pai = pai->esquerda;
                    }
                    filho->info = pai->info;
                    aux->esquerda = pai->direita;
                } 

            }
                
        }
    }
    
    printf("Finalizei a remocao\n");
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

    Insere_arvore_recursiva(&arvore, 114);
    Insere_arvore_recursiva(&arvore, 100);
    Insere_arvore_recursiva(&arvore, 200);
    Insere_arvore_recursiva(&arvore, 180);
    Insere_arvore_recursiva(&arvore, 2454);
    Insere_arvore_recursiva(&arvore, 240);
    Insere_arvore_recursiva(&arvore, 292);

    em_ordem(arvore);
    printf("\n");

    Remove_valor_arvoreABB(arvore, 114);

    em_ordem(arvore);
    printf("\n");
    return 0;
}