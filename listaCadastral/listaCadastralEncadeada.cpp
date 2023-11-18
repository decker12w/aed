#include <iostream>
using namespace std;



struct No {
    int info;
    No* prox;
};

class ListaCadastral {
private:
    No* primeiro;
    No* atual;

public:
    bool estaNaLista(int x);
    void insere(int x, bool& ok);
    void retira(int x, bool& ok);
    bool vazia();
    bool cheia();
    void cria();
    void pegaOPrimeiro(int& x, bool& temElemento);
    void pegaOProximo(int& x, bool& temElemento);
};

bool ListaCadastral::estaNaLista(int x) {
    atual = primeiro;
    while (atual != nullptr) {
        if (atual->info == x) {
            atual = primeiro;
            return true;
        }
        atual = atual->prox;
    }
    atual = primeiro;
    return false;
}

void ListaCadastral::insere(int x, bool& ok) {
    ok = false;
    if (cheia()) {
        return;
    }
    if (estaNaLista(x)) {
        return;
    }
    No* novo = new No;
    novo->info = x;
    novo->prox = nullptr;
    if (vazia()) {
        primeiro = novo;
    } else {
        No* aux;
        while (atual != nullptr) {
            aux = atual;
            atual = atual->prox;
        }
        aux->prox = novo;
    }
    ok = true;
    atual = primeiro;
}

void ListaCadastral::retira(int x, bool& ok) {
    ok = false;
    if (vazia()) {
        return;
    }
    if (primeiro->info == x) {
        No* aux = primeiro;
        primeiro = primeiro->prox;
        delete aux;
        ok = true;
        atual = primeiro;
        return;
    }
    No* anterior = primeiro;
    atual = primeiro->prox;
    while (atual != nullptr) {
        if (atual->info == x) {
            anterior->prox = atual->prox;
            delete atual;
            ok = true;
            atual = primeiro;
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

bool ListaCadastral::vazia() {
    return primeiro == nullptr ? true : false;
}

bool ListaCadastral::cheia() {
    return false;
}

void ListaCadastral::cria() {
    primeiro = nullptr;
    atual = nullptr;
}

void ListaCadastral::pegaOPrimeiro(int& x, bool& ok) {
    if (vazia()) {
        ok = false;
        return;
    }
    atual = primeiro;
    x = primeiro->info;
    ok = true;
}

void ListaCadastral::pegaOProximo(int& x, bool& ok) {
    ok = false;
    if (vazia()) {
        return;
    }
    atual = atual->prox;
    if (atual != nullptr) {
        x = atual->info;
        ok = true;
    }
}

void imprimirLista(ListaCadastral&);
void interseccao(ListaCadastral&, ListaCadastral&, ListaCadastral&);
int main() {
    int x;
    bool ok;
    ListaCadastral listaCadastral1, listaCadastral2, listaCadastralResultado;
    listaCadastral1.cria();
    listaCadastral2.cria();
    listaCadastralResultado.cria();
    listaCadastral1.insere(10, ok);
    listaCadastral1.insere(30, ok);
    listaCadastral1.insere(70, ok);
    listaCadastral1.retira(70, ok);
    listaCadastral2.insere(50, ok);
    listaCadastral2.insere(40, ok);
    listaCadastral2.insere(10, ok);
    cout << "Lista 1" << endl;
    imprimirLista(listaCadastral1);
    interseccao(listaCadastralResultado, listaCadastral1, listaCadastral2);
    cout << "Lista intersecção" << endl;
    imprimirLista(listaCadastralResultado);
}

void imprimirLista(ListaCadastral& listaCadastral) {
    int x;
    bool temElemento;
    listaCadastral.pegaOPrimeiro(x, temElemento);
    while (temElemento) {
        cout << x << endl;
        listaCadastral.pegaOProximo(x, temElemento);
    }
}

void interseccao(ListaCadastral& listaCadastralResultado, ListaCadastral&
    listaCadastral1, ListaCadastral& listaCadastral2) {
    int x;
    bool ok, temElemento;
    listaCadastral1.pegaOPrimeiro(x, temElemento);
    while (temElemento) {
        if (listaCadastral2.estaNaLista(x)) {
            listaCadastralResultado.insere(x, ok);
        }
        listaCadastral1.pegaOProximo(x, temElemento);
    }
}
