#include <iostream>
using namespace std;

const int maximo = 10;

class Fila {
    int elementos[maximo];
    int fim;

public:
    Fila() {
        fim = -1;
    }

    bool vazia() {
        return (fim == -1);
    }

    bool cheio() {
        return (fim == maximo - 1); // Ajuste para checar se a fila está cheia corretamente
    }

    void insere(int x, bool& deuCerto) {
        if (cheio()) {
            deuCerto = false;
        } else {
            fim++;
            elementos[fim] = x;
            deuCerto = true;
        }
    }

    void retira(int& x, bool& deuCerto) {
        if (vazia()) {
            deuCerto = false;
        } else {
            x = elementos[0];
            for (int i = 1; i <= fim; i++) { // Ajuste no loop para a remoção dos elementos
                elementos[i - 1] = elementos[i];
            }
            fim--;
            deuCerto = true;
        }
    }
};

int main() {
    Fila fila;
    bool deuCerto;

    // Testando inserção e remoção na fila
    for (int i = 1; i <= 12; i++) {
        fila.insere(i, deuCerto);
        if (deuCerto) {
            cout << "Inserido: " << i << endl;
        } else {
            cout << "Fila cheia, não foi possível inserir: " << i << endl;
        }
    }

    int x;
    // Removendo elementos da fila
    for (int i = 1; i <= 12; i++) {
        fila.retira(x, deuCerto);
        if (deuCerto) {
            cout << "Removido: " << x << endl;
        } else {
            cout << "Fila vazia, não foi possível remover." << endl;
        }
    }

    return 0;
}
