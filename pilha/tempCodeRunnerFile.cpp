#include <iostream>
// #include "PilhaEstatica.cpp"
#include "PilhaDuplamenteEncadeada.cpp"



void imprimePilha(const Pilha &p1) {
    Pilha aux = p1; // Cria uma cópia da pilha para não alterar a original

    while (!aux.isEmpty()) {
        bool ok;
        int x;
        aux.pop(x,ok);
        std::cout << x << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    Pilha p1;
    int x;
    bool ok;
    p1.push(2,ok);
    p1.push(3,ok);
    p1.push(5,ok);

    imprimePilha(p1);
    p1.pop(x,ok);
    imprimePilha(p1);

    return 0;
}