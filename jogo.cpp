#include <iostream>

using std::string;

class Jogador {
    private:
        int vidas;
    public:
        Jogador() {
            vidas = 3;
        }
        void perdeVida() {
            if (vidas >= 1) {
                vidas -= 1;
            }    
        }
        int getVidas() {
            return vidas;
        }
}; 

class Ingrediente {
    private:
        string nome;
    public:
        Ingrediente() {
        }
        Ingrediente(string n) {
            nome = n;
        }
        string getNome() {
            return nome;
        }
};

class Receita {
    private:
        int quantidade;
        Ingrediente* ingredientesOriginal; // o jogo vai preencher sozinho (array)
        Ingrediente* ingredientes; // jogador vai preencher (pilha)
    public:
        Receita(int q) {
            if (q >= 4 && q <= 10) {
                quantidade = q;
            } else {
                quantidade = 4;
            }
            ingpredientesOriginal = new Ingrediente[quantidade];
            ingredientes = new Ingrediente[quantidade];
        }
        void addIngredienteOriginal(Ingrediente ingrediente, int posicao) {
            if (posicao >= 0 && posicao < quantidade) {
                ingredientesOriginal[posicao] = ingrediente;
            } 
        }
        void addIngrediente(Ingrediente ingrediente) {
        }
};