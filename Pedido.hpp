
#ifndef PEDIDO_H
#define PEDIDO_H

#include <iostream> 

using std::string;

class Pedido {
private:
    const int id;
    string nome;
    int quant;
    string *itens;
    int static pedidosAtivos;
    int static contTodosPedidos;
    int static itensAtivos;
public:
   Pedido(string nome,int quant);
   ~Pedido();
   int getId() const;
   string getNome() const;
   int getQuantidade() const;
   bool getItem(int pos, string& val) const;
   bool setItem(string item, int pos);
   int static totalPedidosAtivos();
   int static totalitensEmPedidosAtivos();
   
};

#endif 
