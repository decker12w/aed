#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Mamifero{
    private:
        int idade;
        string nome;
    public:

        Mamifero(int idade, string nome){
            this->idade = idade;
            this->nome = nome;
        }
        
        void mama(){
            cout << nome << " mama logo " << nome <<" é mamifero" << endl;
        }

        int getIdade(){
            return idade;
        }
        string getNome(){
            return nome;
        }
};


class JoaoVitor: public Mamifero{
    public:
        JoaoVitor(int idade, string nome): Mamifero(idade, nome){

        }
        
};
class Coxa: public Mamifero{
    public:
        Coxa(int idade, string nome): Mamifero(idade, nome){

        }  
};

class JoseMaia: public Mamifero{
    public:
        JoseMaia(int idade, string nome): Mamifero(idade, nome){
        }  
};

JoseMaia operator+(Mamifero m1, Mamifero m2){
    return JoseMaia(20,"jose maia");
}

int main(){
    JoaoVitor joaoVitor(20, "Joao Vitor");
    Coxa coxa(20, "Coxa");
    JoseMaia joseMaia = joaoVitor + coxa;

    cout << joseMaia.getNome() << endl;
    cout << joseMaia.getIdade() << endl;
    coxa.mama() ;
    joaoVitor.mama();
    return 0;
}