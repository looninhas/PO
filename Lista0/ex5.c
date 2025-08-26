//Verifique se uma árvore binária é estrita, sabendo que numa árvore estrita todo nó não folha possui filhos a esquerda e a direita. 
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

int verificando_estrita (No_ABB *arvore){
	if(arvore == NULL)
		return 0;
    else if(arvore->direita == NULL && arvore->esquerda == NULL) // se for apenas a raiz
        return 1;
	else if(arvore->direita != NULL && arvore->esquerda == NULL)
		return 0;
	else if(arvore->esquerda != NULL && arvore->direita == NULL)
		return 0;
	else
		verificando_estrita(arvore->direita) && verificando_estrita(arvore->esquerda); 
}


int main(){
    No_ABB *arvore = NULL;
    Insere_arvore_recursiva(&arvore, 20);
    Insere_arvore_recursiva(&arvore, 15);
    Insere_arvore_recursiva(&arvore, 13);
    Insere_arvore_recursiva(&arvore, 17);
    Insere_arvore_recursiva(&arvore, 49);
    Insere_arvore_recursiva(&arvore, 19);

    if(verificando_estrita(arvore) != 0)
        printf("Arvore estrita\n");
    else
        printf("Arvore nao estrita\n");
    return 0;
}
