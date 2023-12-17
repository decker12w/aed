#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int conteudo;
    struct node *esq;
    struct node *dir;

} Node;

typedef struct {
    Node *raiz;
}Arvore;

void cria(Arvore* a1){
    a1->raiz = NULL;
}

bool vazia(Arvore* a1){
    return a1->raiz == NULL;
}

void inserirAesquerda(Node* node, int elem);
void inserirAdireita(Node* node, int elem);

void inserirAesquerda(Node* node, int elem){
    if(node->esq == NULL){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->conteudo = elem;
        novo->esq = NULL;
        novo->dir = NULL;
        node->esq = novo;
    }
    else{
        if(node->esq->conteudo > elem){
            inserirAesquerda(node->esq, elem);
        }
        else{
            inserirAdireita(node->esq, elem);
        }
    }
}

void inserirAdireita(Node* node, int elem){
    if(node->dir == NULL){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->conteudo = elem;
        novo->esq = NULL;
        novo->dir = NULL;
        node->dir = novo;
    }
    else{
        if(node->dir->conteudo > elem){
            inserirAesquerda(node->dir, elem);
        }
        else{
            inserirAdireita(node->dir, elem);
        }
    }
}

void inserir(Arvore* a1, int elem){
    if(vazia(a1)){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->conteudo = elem;
        novo->esq = NULL;
        novo->dir = NULL;
        a1->raiz = novo;
    }
    else{
        if(a1->raiz->conteudo > elem){
            inserirAesquerda(a1->raiz, elem);
        }
        else{
            inserirAdireita(a1->raiz, elem);
        }
    }
}

void imprimirArvore(Node* node){
    if(node != NULL){
        printf("%d ", node->conteudo);
        imprimirArvore(node->esq);
        imprimirArvore(node->dir);
    }
}

int main(){
    
    Arvore a1;
    cria(&a1);

    inserir(&a1, 10);
    inserir(&a1, 15);
    inserir(&a1, 20);

    imprimirArvore(a1.raiz);

    return 0;
}
