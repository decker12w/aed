#include <iostream>

using namespace std;

class Vector {
    public:
        int x;
        int y;
        int z;

    Vector (){
        this->x = 0;
        this->y = 0;
        this->z = 0;
    }
    Vector (int x , int y, int z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    Vector operator*(Vector v1)const{
        Vector v3;
        v3.x = x*v1.x;
        v3.y = y*v1.y;
        v3.z = z*v1.z;
        return v3;
    }

    Vector operator++(int){
        Vector aux(*this); // copy current values
        ++x;
        ++y;
        ++z;
        return aux; // return old values
    }

    friend Vector operator+(Vector v1, Vector v2);
    friend Vector operator++(Vector& v1);
    friend const Vector operator*(int v1, Vector v2);
};

Vector operator+(Vector v1, Vector v2){
    Vector v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
    return v3;
}

const Vector operator*(int v1, Vector v2){
    Vector v3;
    v3.x = v1 * v2.x;
    v3.y = v1* v2.y;
    v3.z = v1* v2.z;
    return v3;
}
Vector operator++(Vector& v1){
    ++v1.x;
    ++v1.y;
    ++v1.z;

    return v1;
};

int main(int argc, const char** argv) {
    Vector v1(1,1,1),v2(1,1,1),v3;

    v3 = v1+v2;
    v3 = v3 * v3; 
    ++v3;
    v3++;
    v3 = 5*v3;

    cout << v3.x << endl;
    cout << v3.y << endl;
    cout << v3.z << endl;
    return 0;
}