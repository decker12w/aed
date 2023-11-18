#include <iostream>

const int tamanho = 10;

class Pilha{
    private:
        int top;
        int elementos[tamanho];
    public:
        Pilha(){
            top = -1;
        }

        bool vazia(){
            return (top == 0);
        }
        bool cheio(){
            return (top == tamanho);
        }
        bool empilha(int x){
            if(cheio()){
                return false;
            }
            elementos[tamanho] = x;
            top++;
            return true;
        }
        bool desempilha(int &x){
            if(vazia()){
                return false;
            }

            x = elementos[tamanho];
            top--;
            return true
        }
};

