#include <iostream>

using namespace std;

typedef struct node {
    int info;
    node* esq;
    node* dir;
} Node;

void cria(Node* &arvore) {
    arvore = nullptr;
}

bool vazia(Node* arvore) {
    return arvore == nullptr;
}

bool estaNaArvore(Node* arvore, int x) {
    if (vazia(arvore)) {
        return false;
    }
    if (arvore->info == x) {
        return true;
    }
    return (estaNaArvore(arvore->esq, x) || estaNaArvore(arvore->dir, x));
}

void insere(Node* &arvore, int x) {
    if (vazia(arvore)) {
        Node* novo = new Node;
        novo->info = x;
        novo->esq = nullptr;
        novo->dir = nullptr;
        arvore = novo;
    } else {
        if (arvore->info > x) {
            insere(arvore->esq, x);
        } else {
            insere(arvore->dir, x);
        }
    }
}

void retira(Node* &arvore, int x) {
    if (!vazia(arvore)) {
        if (arvore->info == x) {
            if (arvore->esq == nullptr && arvore->dir == nullptr) {
                delete arvore;
                arvore = nullptr;
            } else if (arvore->esq != nullptr && arvore->dir == nullptr) {
                Node* aux = arvore;
                arvore = arvore->esq;
                delete aux;
                aux = nullptr;
            } else if (arvore->esq == nullptr && arvore->dir != nullptr) {
                Node* aux = arvore;
                arvore = arvore->dir;
                delete aux;
                aux = nullptr;
            } else {
                Node* maiorDaSubarvoreEsquerda = arvore->esq;
                while (maiorDaSubarvoreEsquerda->dir != nullptr) {
                    maiorDaSubarvoreEsquerda = maiorDaSubarvoreEsquerda->dir;
                }
                arvore->info = maiorDaSubarvoreEsquerda->info;
                retira(arvore->esq, arvore->info);
            }
        } else if (arvore->info > x) {
            retira(arvore->esq, x);
        } else {
            retira(arvore->dir, x);
        }
    }
}

int somaElementos(Node* arvore) {
    if (arvore == nullptr) {
        return 0;
    }
    int esq = somaElementos(arvore->esq);
    int dir = somaElementos(arvore->dir);
    return arvore->info + esq + dir;
}

bool arvoresIguais(Node* arvore1, Node* arvore2) {
    if ((arvore1 == nullptr && arvore2 != nullptr) || (arvore1 != nullptr && arvore2 == nullptr)) {
        return false;
    }
    if (arvore1 == nullptr && arvore2 == nullptr) {
        return true;
    }
    if (arvore1->info != arvore2->info) {
        return false;
    }
    return (arvoresIguais(arvore1->esq, arvore2->esq)) && (arvoresIguais(arvore1->dir, arvore2->dir));
}

int main() {
    Node* arvore1;
    Node* arvore2;
    cria(arvore1);
    cria(arvore2);
    insere(arvore1, 10);
    insere(arvore1, 5);
    insere(arvore1, 20);
    insere(arvore1, 40);
    insere(arvore1, 8);
    insere(arvore2, 10);
    insere(arvore2, 5);
    insere(arvore2, 20);
    insere(arvore2, 40);
    insere(arvore2, 8);

    cout << arvoresIguais(arvore1, arvore2) << endl;
    cout << somaElementos(arvore1) << endl;
    retira(arvore1, 10);
    cout << arvoresIguais(arvore1, arvore2) << endl;
    cout << somaElementos(arvore1) << endl;
    cout << estaNaArvore(arvore1, 10) << endl;
    cout << estaNaArvore(arvore2, 20) << endl;
}