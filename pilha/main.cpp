#include <iostream>
// #include "PilhaEstatica.cpp"
#include "PilhaDuplamenteEncadeada.cpp"



void imprimePilha(const Pilha &p1) {
    Pilha aux = p1; // Cria uma cópia da pilha para não alterar a original
    bool ok;
    int x;

    // Enquanto houver elementos na pilha auxiliar, imprime-os
    while (!aux.isEmpty()) {
        // aux.top(x); // Obtém o valor do topo sem remover
        std::cout << x << std::endl;
        aux.pop(x, ok); // Remove o elemento do topo da pilha auxiliar
    }
}

int main(int argc, char const *argv[]) {
    Pilha p1;
    int x;
    bool ok;
    p1.push(2, ok);
    p1.push(3, ok);
    p1.push(5, ok);

    imprimePilha(p1);

    // Copiando novamente a pilha original
    Pilha p2 = p1;
    p2.pop(x, ok); // Remove o elemento da pilha
    imprimePilha(p2); // Imprime a pilha modificada

    return 0;
}
