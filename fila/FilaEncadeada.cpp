#include <iostream>

// Definição da estrutura Node
struct Node {
    int data;
    Node* prox;
};

// Definição da classe Fila
class Fila {
    Node* primeiro;
    Node* ultimo;

public:
    Fila() {
        primeiro = nullptr;
        ultimo = nullptr;
    }

    bool vazia() {
        return (primeiro == nullptr);
    }

    bool cheio() {
        return false;
    }

    void insere(int x, bool& ok) {
        if (cheio()) {
            ok = false;
        }
        else {
            Node* ptr = new Node();
            ptr->data = x;

            if (primeiro == nullptr) {
                primeiro = ptr;
                ultimo = ptr;
                ptr->prox = ptr;
            }
            else {
                ultimo->prox = ptr;
                ultimo = ptr;
            }
            ok = true;
        }
    }

    void remove(int& x, bool& ok) {
        if (vazia()) {
            ok = false;
        }
        else {
            Node* remove = primeiro;
            x = remove->data;

            if (primeiro == ultimo) {
                primeiro = nullptr;
                ultimo = nullptr;
            }
            else {
                primeiro = primeiro->prox;
            }
            delete remove;
            ok = true;
        }
    }

    void mostraFila() {
        if (vazia()) {
            std::cout << "Fila vazia" << std::endl;
            return;
        }

        Node* temp = primeiro;
        std::cout << "Conteúdo da fila: ";
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->prox;
        }
        std::cout << std::endl;
    }
};

int main() {
    Fila fila;
    bool ok;

    // Inserindo elementos na fila
    fila.insere(10, ok);
    fila.insere(20, ok);
    fila.insere(30, ok);

    // Visualizando a fila
    fila.mostraFila();

    // Removendo elementos da fila e exibindo
    int valor_removido;
    fila.remove(valor_removido, ok);
    fila.remove(valor_removido, ok);
    fila.remove(valor_removido, ok);
    std::cout << "Valor removido: " << valor_removido << std::endl;

    // Visualizando a fila após a remoção
    fila.mostraFila();

    return 0;
}
