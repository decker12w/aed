#include <iostream>
#include <math.h>

class Ponto{
    private:
        int x;
        int y;
    public:
        int getX(){
            return x;
        };
        int getY(){
            return y;
        };
};

class Vetor{
    private:
        int modulo;
        int x;
        int y;
        Ponto* pontos;


    Vetor operator+(Vetor v){

        
    };

    public:
        Vetor(Ponto* p1, Ponto* p2){
            x = p2->getX() - p1->getX();
            y = p2->getY() - p1->getY();
            modulo = sqrt(pow(x, 2) + pow(y, 2));
            pontos = new Ponto[2] { *p1, *p2 };
        };
};