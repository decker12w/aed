#include <iostream>

struct Node {
    int data;
    Node* esq;
    Node* dir;
};

struct Fila {
    Node* primeiro;
    Node* ultimo;
};

bool vazia(Fila* F) {
    return F->primeiro == nullptr;
}

void retira(Fila* f, int &x, bool &ok) {
    if (vazia(f)) {
        ok = false;
        return;
    } else {
        Node* remover = f->primeiro;

        if (f->primeiro == f->ultimo) {
            f->primeiro = nullptr;
            f->ultimo = nullptr;
        } else {
            f->primeiro = f->primeiro->dir;
            f->ultimo->dir = f->primeiro;
            f->primeiro->esq = f->ultimo;
        }

        x = remover->data;
        delete remover;
        ok = true;
    }
}

void destroi(Fila* f) {
    int x;
    bool ok;

    while (!vazia(f)) {
        retira(f, x, ok);
    }
}

void insere(Fila* f, int valor) {
    Node* novo = new Node;
    novo->data = valor;

    if (vazia(f)) {
        f->primeiro = novo;
        f->ultimo = novo;
        novo->esq = novo;
        novo->dir = novo;
    } else {
        novo->esq = f->ultimo;
        novo->dir = f->primeiro;
        f->ultimo->dir = novo;
        f->ultimo = novo;
        f->primeiro->esq = f->ultimo;
    }
}
void mostraFila(Fila* f) {
    if (vazia(f)) {
        std::cout << "Fila vazia." << std::endl;
        return;
    }

    Node* atual = f->primeiro;
    do {
        std::cout << atual->data << " ";
        atual = atual->dir;
    } while (atual != f->primeiro);

    std::cout << std::endl;
}

int main() {
    Fila fila;
    fila.primeiro = nullptr;
    fila.ultimo = nullptr;

    // Inserindo elementos na fila
    insere(&fila, 32);
    insere(&fila, 90);
    insere(&fila, 30);
    insere(&fila, 20);

    int valor;
    bool ok;

    // Testando a retirada de um elemento
    retira(&fila, valor, ok);

    if (ok) {
        std::cout << "Elemento retirado: " << valor << std::endl;
    } else {
        std::cout << "Não foi possível retirar um elemento. A fila está vazia." << std::endl;
    }

    // Limpando a fila
    destroi(&fila);

    return 0;
}
