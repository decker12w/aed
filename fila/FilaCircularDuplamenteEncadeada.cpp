#include <iostream>

struct Node {
    int data;
    Node* dir;
    Node* esq;
};

class FilaCircularDuplamenteEncadeada{
    private:
        Node* primeiro;
        Node* ultimo;
    public:
        FilaCircularDuplamenteEncadeada(){
            primeiro = nullptr;
            ultimo = nullptr;
        }

        ~FilaCircularDuplamenteEncadeada(){
            while(!vazia()){
                int x;
                bool ok;
                retira(x,ok);
            }
        }

        bool cheia(){
            return false;
        }

        bool vazia(){

            return primeiro == nullptr && ultimo == nullptr;
        }

        void retira(int &x, bool &ok){
            Node* anterior;
            if (vazia()){
                ok = false;
                return;
            }
            else {
                if (primeiro = ultimo){
                    primeiro = nullptr;
                    ultimo = nullptr;
                    return;
                }
                anterior = primeiro;
                anterior->dir->esq = anterior->esq;
                primeiro = anterior->dir;
                ultimo->dir = primeiro;
                x = anterior->data;
                delete anterior;
                ok = true;


            }
        }

};