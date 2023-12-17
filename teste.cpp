#include <iostream>

class qualquer{
    public:
        int idade;
        std::string nome;
        static int atributo;
        int metodo(){
            return 1+atributo;
        }
        static int metodoEstatico(){
            
        }
};

int main(int argc, const char** argv) {
    
    qualquer * ptr = new qualquer();
    ptr->idade = 5;
    std::cout << ptr->idade << std::endl;


    
    return 0;
}