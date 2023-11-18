#include <iostream>

struct Node{
    int data;
    Node* prox;
};

class ListaCadastralCircularEncadeada{
    private:
        Node* primeiro;
        Node* atual;

    public:
        ListaCadastralCircularEncadeada();
        bool cheio() const;
        bool vazio() const;
        void pegaOPrimeiro( int& x,bool& deuCerto);
        void pegaOProximo(int& x,bool& deuCerto);
        bool estaNaLista(int x);
        void insere(int x, bool &deuCerto );
        void retira(int x, bool& ok);   
};

ListaCadastralCircularEncadeada::ListaCadastralCircularEncadeada(){
    primeiro = nullptr;
    atual = nullptr;
}
bool ListaCadastralCircularEncadeada::cheio()const{
    return false;
}
bool ListaCadastralCircularEncadeada::vazio()const{
    return primeiro == nullptr && atual == nullptr;
}
void ListaCadastralCircularEncadeada::pegaOPrimeiro(int& x,bool& deuCerto) {
    if (vazio()) {
        deuCerto = false;
        return;
    }
    atual = primeiro;
    x = atual->data; 
    deuCerto = true;
}


void ListaCadastralCircularEncadeada::pegaOProximo(int& x,bool& deuCerto) {
    if (vazio()) {
        deuCerto = false;
        return;
    }

    if(atual->prox == primeiro){
        deuCerto = false;
        return;
    }
    atual = atual->prox;
    x = atual->data;
    deuCerto = true;
}



bool ListaCadastralCircularEncadeada::estaNaLista(int x) {
    if (vazio()){
        return false;
    }
    
    atual = primeiro;
    
    do {
        if (atual->data == x){
           x = atual->data;
           return true; 
        }
        atual = atual->prox;
    } while(atual != primeiro);

    return false;
}
void ListaCadastralCircularEncadeada::insere(int x, bool &deuCerto) {
    Node* newptr = new Node();
    newptr->data = x;
    newptr->prox = nullptr;

    if (cheio()) {
        deuCerto = false;
        return;
    }

    if (estaNaLista(x)) {
        deuCerto = false;
        return;
    }

    if (vazio()) {
        // Lista vazia, insere o primeiro elemento
        primeiro = newptr;
        atual = newptr;
        atual->prox = primeiro;  // Torna a lista circular
        deuCerto = true;
        return;
    } else {
        // Inserir no final da lista
        Node* temp = primeiro;
        while (temp->prox != primeiro) {
            temp = temp->prox;
        }
        temp->prox = newptr;  // Conecta o novo elemento ao último nó
        newptr->prox = primeiro;  // Torna a lista circular
    }

    deuCerto = true;
}


void ListaCadastralCircularEncadeada::retira(int x, bool& ok) {
    if (vazio()) {
        return;
    }

    Node* anterior;
    Node* remover;

    if (primeiro->data == x) {
        if (atual == primeiro) {
            delete atual->prox;
            atual = nullptr;
            primeiro = nullptr;
            ok = true;
            return;
        }

        Node* aux = primeiro;
        primeiro = aux->prox;
        delete aux;
        ok = true;
        return;
    }

    atual = primeiro;
    do {
        if (atual->prox->data == x) {
            x = atual->data;
            remover = atual->prox;
            atual->prox = remover->prox;
            delete remover;
        }
        atual = atual->prox;
    } while (atual != primeiro);
}

    
    


void imprimirLista(ListaCadastralCircularEncadeada& listaCadastral) {
    int x;
    bool temElemento;
    listaCadastral.pegaOPrimeiro(x, temElemento);
    while(temElemento){
        std::cout << x << std::endl;
        listaCadastral.pegaOProximo(x, temElemento);
    }
    
}

int main() {
    ListaCadastralCircularEncadeada l1;
    bool deuCerto;
    int x;
    int y;

    l1.insere(1, deuCerto);
    l1.insere(2, deuCerto);
    l1.insere(3, deuCerto);
    l1.insere(4, deuCerto);
    l1.insere(5, deuCerto);
    l1.insere(6, deuCerto);

    imprimirLista(l1);

    return 0;
}

