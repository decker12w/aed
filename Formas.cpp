#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class FormasGeometricas2D {
private:
    const string nome;
    int altura;
    int comprimento;
    static int numeroDeFormas;
protected:
    static const double pi; // Declaração de pi como uma variável estática protegida
public:
    FormasGeometricas2D(string nome, int altura, int comprimento)
        : nome(nome), altura(altura), comprimento(comprimento) {
        numeroDeFormas++;
    }

    int getAltura() const {
        return altura;
    }

    int getComprimento() const {
        return comprimento;
    }

    string getNome() const {
        return nome;
    }

    void setAltura(int novaAltura) {
        altura = novaAltura;
    }

    void setComprimento(int novoComprimento) {
        comprimento = novoComprimento;
    }

    virtual int getArea() const = 0; // Método virtual puro para obter a área
};

const double FormasGeometricas2D::pi = 3.14; // Definição de pi
int FormasGeometricas2D::numeroDeFormas = 0; 

class Circulo : public FormasGeometricas2D {
private:
    int raio;
public:
    Circulo(string nome, int altura, int comprimento, int raio)
        : FormasGeometricas2D(nome, altura, comprimento), raio(raio) {}

    int getRaio() const {
        return raio;
    }

    void setRaio(int novoRaio) {
        raio = novoRaio;
    }

    int getArea() const override {
        return static_cast<int>(pi * raio * raio);
    }
};

class Triangulo : public FormasGeometricas2D {
public:
    Triangulo(string nome, int altura, int comprimento)
        : FormasGeometricas2D(nome, altura, comprimento) {}

    int getArea() const override {
        return (getAltura() * getComprimento()) / 2;
    }
};

int main() {
    Circulo circulo("Circulo", 10, 10, 10);
    Triangulo triangulo("Triangulo", 10, 1);

    cout << "Área do círculo: " << circulo.getArea() << endl;
    cout << "Área do triângulo: " << triangulo.getArea() << endl;

    return 0;
}
