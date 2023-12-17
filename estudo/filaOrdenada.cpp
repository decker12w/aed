#include <iostream>

struct Node {
    int idade;
    Node* prox;
};

using NodePtr = Node*;

class FilaDeVacinacao {
    NodePtr primeiro;

public:
    FilaDeVacinacao() {
        primeiro = nullptr;
    }

    bool cheio() {
        return false;
    }

    bool vazia() {
        return (primeiro == nullptr);
    }

    void insere(bool& ok, int x) {
        if (cheio()) {
            ok = false;
        } else {
            Node* novo = new Node();
            novo->idade = x;
            novo->prox = novo;

            if (vazia()) {
                primeiro = novo;
                return;
            }

            if (primeiro->idade < novo->idade) {
                Node* ultimo = primeiro;
                while (ultimo->prox != primeiro) {
                    ultimo = ultimo->prox;
                }
                novo->prox = primeiro;
                primeiro = novo;
                ultimo->prox = primeiro;
            } else {
                Node* aux = primeiro;
                Node* anterior = nullptr;
                while (aux->idade >= novo->idade) {
                    if (aux->prox == primeiro) {
                        aux->prox = novo;
                        novo->prox = primeiro;
                        return;
                    }
                    anterior = aux;
                    aux = aux->prox;
                }
                anterior->prox = novo;
                novo->prox = aux;
            }
        }
    }

    void mostraFila() {
        if (vazia()) {
            std::cout << "Fila vazia." << std::endl;
            return;
        }

        Node* atual = primeiro;
        do {
            std::cout << atual->idade << " ";
            atual = atual->prox;
        } while (atual != primeiro);

        std::cout << std::endl;
    }
};

int main() {
    FilaDeVacinacao fila;

    bool ok = true;
    fila.insere(ok, 30);
    fila.insere(ok, 40);
    fila.insere(ok, 25);
    fila.insere(ok, 40);
    fila.insere(ok, 35);
    fila.insere(ok, 99);

    fila.mostraFila();

    return 0;
}
