#include <iostream>
#include "Pedido.hpp"

using std::string;

int Pedido::pedidosAtivos = 0;
int Pedido::contTodosPedidos = 0;
int Pedido::itensAtivos = 0;

Pedido::Pedido(string nome, int quant) : id(++pedidosAtivos)
{
    this->nome = nome;
    if (quant > 0){
        this->quant = quant;
        this->itens = new string[quant];
    }
    else {
        this->quant = quant;
        this->itens = nullptr;

    }
    contTodosPedidos++;
    itensAtivos = itensAtivos + quant;  
}

Pedido::~Pedido(){
   pedidosAtivos--;
   itensAtivos = itensAtivos - totalitensEmPedidosAtivos();
   if (totalitensEmPedidosAtivos()>0)
   		delete [] itens;
}

bool Pedido::getItem(int pos, string& val) const {
    if (pos >= 0 && pos < quant) {
        val = itens[pos];
        return true;
    }
    return false;
}

bool Pedido::setItem(string item, int pos){
    if(pos >=0 && pos < itensAtivos){
        itens[pos] = item;
    }
    else 
        return false;
};


int Pedido::getId() const{
	return id;
}

string Pedido::getNome() const { 
    return nome;
 };
int Pedido::getQuantidade() const{
    return quant;    
};

int Pedido::totalPedidosAtivos(){
    return contTodosPedidos;
};
int Pedido::totalitensEmPedidosAtivos(){
    return itensAtivos;
};