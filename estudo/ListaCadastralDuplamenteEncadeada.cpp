#include <iostream>

struct Node {
    int data;
    Node* dir;
    Node* esq;
};

class Lista {
private:
    Node* primeiro;
    Node* atual;

public:
    Lista() {
        primeiro = nullptr;
        atual = nullptr;
    }

    bool vazia() {
        return (primeiro == nullptr);
    }

    bool cheio() {
        return false;
    }

    bool estaNaLista(int x) {
        if (vazia())
            return false;

        atual = primeiro;
        do {
            if (atual->data == x) {
                return true;
            }
            atual = atual->dir;
        } while (atual != primeiro);

        return false;
    }


    void insere(int x, bool& ok) {
        if (cheio()) {
            ok = false;
            return;
        }
        if (estaNaLista(x)) {
            ok = false;
            return;
        } else {
            Node* novo = new Node();
            novo->data = x;

            if (vazia()) {
                primeiro = novo;
                atual = novo;
                novo->dir = novo;
                novo->esq = novo;
                return;
            }

            Node* aux = primeiro;

            while (aux->dir != primeiro) {
                aux = aux->dir;
            }

            aux->dir = novo;
            novo->esq = aux;
            novo->dir = primeiro;
            primeiro->esq = novo;
        }
    }

    void pegaOprimeiro(int& x, bool& ok){
        if(vazia()){
            ok = false;
            return;
        }

        atual = primeiro;
        x = primeiro->data;
        ok = true;
    }

    void pegaOproximo(int& x, bool& ok){
        if(vazia()){
            ok = false;
            return;
        }
        if(atual->dir == primeiro){
            ok = false;
            return;
        }
        atual = atual->dir;
        x = atual->data; // Corrigido para pegar o valor do nó atual
        ok = true;
}

};

// Função para mostrar a lista
void mostraLista(Lista& lista) {
    int x;
    bool ok;

    lista.pegaOprimeiro(x,ok);
    while(ok != false){

        std::cout << x << std::endl;
        lista.pegaOproximo(x,ok);
    }
}

int main() {
    Lista minhaLista;
    bool insercaoOK = true;

    minhaLista.insere(10, insercaoOK);
    minhaLista.insere(20, insercaoOK);
    minhaLista.insere(30, insercaoOK);
    minhaLista.insere(10, insercaoOK);
    minhaLista.insere(20, insercaoOK);
    minhaLista.insere(30, insercaoOK);
    minhaLista.insere(10, insercaoOK);
    minhaLista.insere(20, insercaoOK);
    minhaLista.insere(30, insercaoOK);
    minhaLista.insere(10, insercaoOK);
    minhaLista.insere(20, insercaoOK);
    minhaLista.insere(30, insercaoOK);

    mostraLista(minhaLista);

    return 0;
}
