#include <iostream>

struct Node {
    int data;
    Node* esq;
    Node* dir;
};

class Lista {
private:
    Node* header;
    Node* primeiro;
    Node* atual;

public:
    Lista() {
        header = new Node(); // Criação do nó cabeçalho vazio
        header->esq = header;
        header->dir = header;
        primeiro = header; // Apontando primeiro para o header
        atual = header; 
    }

    bool cheia() {
        return false; // Lista encadeada não está limitada por capacidade de tamanho fixo
    }

    bool vazia() {
        return primeiro == header ? true: false; // A lista está vazia se o nó cabeçalho aponta para si mesmo
    }

    void pegaOPrimeiro(int& x, bool& ok) {
        if (vazia()) {
            ok = false;
            return;
        }

        atual = primeiro;
        x = primeiro->data;
        ok = true;
    }

    void pegaOProximo(int& x, bool& ok) {
        if (vazia()) {
            ok = false;
            return;
        }

        atual = atual->dir;
        x = atual->data;
        ok = true;
    }

    bool estaNaLista(int x) {
        if (vazia()) {
            return false;
        }

        atual = primeiro;
        while(atual != header){
            if(atual->data == x){
                return true;
            }
            atual = atual->dir;
        }
        atual = primeiro;
        return false;
        
    }
    void insere(int x, bool& ok) {
        if (estaNaLista(x)) {
            ok = false; // Se o elemento já existe na lista, não insira novamente
            return;
        }

        Node* ptr = new Node();
        ptr->data = x;

        if (vazia()) {
            // Se a lista estiver vazia, o novo nó é o único na lista
            primeiro = ptr;
            atual = ptr;
            ptr->dir = header;
            ptr->esq = header;
            header->dir = ptr;
            header->esq = ptr;
        } else {
            // Se a lista não estiver vazia, insira o novo nó no final da lista
            Node* ultimo = header->esq;
            ultimo->dir = ptr;
            ptr->esq = ultimo;
            ptr->dir = header;
            header->esq = ptr;
        }

        ok = true; // A inserção foi bem-sucedida
}

void remove(int& x, bool& ok) {
        Node* ptr = new Node();
        ptr->data = x;

        if (vazia()) {
            ok = false;
            return;
        } 
        
        else {
            // Se a lista não estiver vazia, insira o novo nó no final da lista
            Node* ultimo = header->esq;
            ultimo->dir = ptr;
            ptr->esq = ultimo;
            ptr->dir = header;
            header->esq = ptr;
        }

        ok = true; // A inserção foi bem-sucedida
}
};


