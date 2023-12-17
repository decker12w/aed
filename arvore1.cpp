#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int conteudo;
    struct node *esq;
    struct node *dir;

} Node;

void cria(Node** raiz){
    *raiz = NULL;
}

bool vazia(Node* raiz){
    return raiz == NULL;
}

bool estaNaArvore(Node* raiz, int valor){
    if(vazia(raiz)){
        return false;
    }
    else{
        if(raiz->conteudo == valor){
            return true;
        }
        else{
            return estaNaArvore(raiz->esq,valor) || estaNaArvore(raiz->dir,valor);
        }
    }
}

Node* insere(Node* raiz, int valor){
    if(vazia(raiz)){
        Node* novo = (Node*)malloc(sizeof(Node));
        novo->conteudo = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
    else{
        if(raiz->conteudo > valor){
            raiz->esq = insere(raiz->esq,valor);
        }
        else if(raiz->conteudo < valor){
            raiz->dir = insere(raiz->dir,valor);
        }
        return raiz;
    }
}

void imprimir(Node* raiz){
    if(!vazia(raiz)){
        printf("%d\n",raiz->conteudo);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
}

int main(){

    Node* raiz;
    cria(&raiz);
    raiz = insere(raiz,10);
    raiz = insere(raiz,20);
    raiz = insere(raiz,30);
    imprimir(raiz);

    if(estaNaArvore(raiz, 10)){
        printf("Esta na arvore\n");
    }
    else{
        printf("Nao esta na arvore\n");
    }
    if(vazia(raiz)){
        printf("Arvore vazia\n");
    }
        
    return 0;
}