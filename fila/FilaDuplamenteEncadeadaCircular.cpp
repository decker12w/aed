#include <iostream>

struct Node {
    int data;
    Node* esq;
    Node* dir;
};

class Fila {
private:
    Node* primeiro;
    Node* ultimo;
public:
    Fila() : primeiro(nullptr), ultimo(nullptr) {}

    bool cheio() {
        // Implemente a lógica de fila cheia se necessário
        return false; // Por enquanto, sempre retorna falso
    }

    bool vazia() {
        return (primeiro == nullptr && ultimo == nullptr);
    }

    void insere(int x, bool& ok) {
        if (cheio()) {
            ok = false;
        } else {
            Node* ptr = new Node();
            ptr->data = x;

            if (primeiro == nullptr) {
                primeiro = ptr;
                ultimo = ptr;
                ptr->dir = primeiro;
                ptr->esq = primeiro;
            } else {
                ptr->dir = primeiro;
                ptr->esq = ultimo;
                ultimo->dir = ptr;
                primeiro->esq = ptr;
                ultimo = ptr;
            }
            ok = true;
        }
    }

    void retira(int& x, bool& ok) {
        if (vazia()) {
            ok = false;
        } else {
            x = primeiro->data;
            Node* remover = primeiro;
            if (primeiro == ultimo) {
                primeiro = nullptr;
                ultimo = nullptr;
            } else {
                primeiro = primeiro->dir;
                ultimo->dir = primeiro;
                primeiro->esq = ultimo;
            }
            delete remover;
            ok = true;
        }
    }

    void imprimeFila() {
        if (vazia()) {
            std::cout << "Fila vazia!" << std::endl;
            return;
        }

        Node* atual = primeiro;
        do {
            std::cout << atual->data << " ";
            atual = atual->dir;
        } while (atual != primeiro);
        std::cout << std::endl;
    }
};

int main() {
    Fila fila;
    bool ok;

    std::cout << "Fila vazia? " << (fila.vazia() ? "Sim" : "Não") << std::endl;

    fila.insere(10, ok);
    fila.insere(20, ok);
    fila.insere(30, ok);
    fila.insere(40, ok);

    std::cout << "Fila vazia? " << (fila.vazia() ? "Sim" : "Não") << std::endl;

    std::cout << "Elementos da fila: ";
    fila.imprimeFila();

    int elementoARetirar = 0;
    fila.retira(elementoARetirar, ok);
    std::cout << "Elemento retirado: " << elementoARetirar << std::endl;

    std::cout << "Elementos da fila após retirada: ";
    fila.imprimeFila();

    return 0;
}