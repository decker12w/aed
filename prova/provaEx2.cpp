// #include <iostream>

// struct Node {
//     int idade;
//     Node* prox;
// };

// class FilaVacina {
// public:
//     Node* inicio;

//     FilaVacina() : inicio(nullptr) {}

//     void insere(Fila& fv ,int novaIdade) {
//         Node* novo = new Node();
//         novo->idade = novaIdade;


//         if (fv->fv == nullptr || novaIdade > fv->fv->idade) {
//             if (fv->fv == nullptr) {
//                 fv->fv = novo;
//                 novo->prox = fv->fv;
//             } else {
//                 Node* aux = fv->fv;
//                 while (aux->prox != fv->fv) {
//                     aux = aux->prox;
//                 }
//                 aux->prox = novo;
//                 novo->prox = fv->fv;
//                 fv->fv = novo;
//             }
//         } else {
//             Node* aux = inicio;
//             while (aux->prox != inicio && aux->prox->idade >=novaIdade) {
//                 if (aux->prox->idade > novaIdade) {
//                     aux = aux->prox;
//                 } else {
//                     break;
//                 }
//             }
//             novo->prox = aux->prox;
//             aux->prox = novo;
//         }
//     }


    // void insere(int y, int x) {
    //         Node* ptrNovo = new Node();
    //         ptrNovo->data = x;
    //         ptrNovo->prox = ptrNovo;

    //         if (inicio == nullptr) {
    //             inicio = ptrNovo;
    //             return;
    //         }

    //         Node* aux = inicio;

    //         if (ptrNovo->data > inicio->data) {
    //             inicio = ptrNovo;
    //             inicio->prox = aux;
    //             aux->prox = inicio;
    //         } else {
    //             while (aux->prox != inicio) {
    //                 if (ptrNovo->data > aux->prox->data) {
    //                     ptrNovo->prox = aux->prox;
    //                     aux->prox = ptrNovo;
    //                     return;
    //                 } else if (ptrNovo->data == aux->prox->data) {
    //                     ptrNovo = aux->prox->prox;
    //                     ptrNovo = aux->prox;
    //                     return;
    //                 }
    //                 aux = aux->prox;
    //             }
    //             aux->prox = ptrNovo;
    //             aux = aux->prox;
    //             aux->prox = inicio;
    //         }

//     void mostrarFila() {
//         Node* atual = inicio;

//         if (atual == nullptr) {
//             std::cout << "Fila vazia.\n";
//             return;
//         }

//         Node* aux = atual;
//         do {
//             std::cout << "Idade: " << aux->idade << std::endl;
//             aux = aux->prox;
//         } while (aux != inicio);
//     }
// };

    
// int main() {
//     FilaVacina fila;

//     fila.insere(40);
//     fila.insere(30);
//     fila.insere(50);
//     fila.insere(30);
//     fila.insere(45);
//     fila.insere(1000);
//     fila.insere(1);

//     fila.mostrarFila();

//     return 0;
// }
 
//  void insere(fila& fila, int novaIdade) {
//         Node* novo = new Node();
//         novo->idade = novaIdade;

//         if (fila->inicio == nullptr || novaIdade > fila->inicio->idade) {
//             if (fila->inicio == nullptr) {
//                 fila->inicio = novo;
//                 novo->prox = fila->inicio;
//             } else {
//                 Node* aux = fila->inicio;
//                 while (aux->prox != fila->inicio) {
//                     aux = aux->prox;
//                 }
//                 aux->prox = novo;
//                 novo->prox = fila->inicio;
//                 fila->inicio = novo;
//             }
//         } else {
//             Node* aux = fila->inicio;
//             while (aux->prox != fila->inicio && aux->prox->idade >= novaIdade) {
//                 if (aux->prox->idade > novaIdade) {
//                     aux = aux->prox;
//                 } else {
//                     break;
//                 }
//             }
//             novo->prox = aux->prox;
//             aux->prox = novo;
//         }
//     }