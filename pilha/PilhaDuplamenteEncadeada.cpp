#include <iostream>

// Definição da estrutura do nó
struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Pilha {
private:
    Node* top; // Apontador para o topo da pilha

public:
    Pilha() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    // Retorna o valor do topo da pilha sem removê-lo
    bool topValue(int& x) {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return false;
        }

        x = top->data;
        return true;
    }


    // Adiciona um elemento no topo da pilha
    void push(int value, bool &deuCerto) {
        Node* newNode = new Node();
        newNode->data = value;

        if (top == nullptr) {
            newNode->prev = newNode;
            newNode->next = newNode;
            top = newNode;
            deuCerto = true;
        } else {
            Node* last = top->prev;
            newNode->next = top;
            newNode->prev = last;
            top->prev = newNode;
            last->next = newNode;
            top = newNode;
            deuCerto = true;
        }
    }

    // Remove o elemento do topo da pilha
    void pop(int& x, bool &deuCerto) {
    if (isEmpty()) {
        std::cout << "Stack underflow!" << std::endl;
        deuCerto = false;
        return;
    }

    Node* temp = top;
    x = temp->data;
    if (top->next == top) {
        top = nullptr;
    } else {
        top->prev->next = top->next;
        top->next->prev = top->prev;
        top = top->next;
    }

    delete temp;
    deuCerto = true;
}


};


