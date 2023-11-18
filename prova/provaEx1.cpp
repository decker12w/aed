// A)
// bool vazia(Fila* F) {
//     return F->primeiro == nullptr;
// }

// void retira(Fila& f,int &x, bool &ok){
//             Node* anterior;
//             if (vazia(f)){
//                 ok = false;
//                 return;
//             }
//             else {
//                 if (f->primeiro == f->ultimo){
//                     f->primeiro = nullptr;
//                     f->ultimo = nullptr;
//                     return;
//                 }
//                 anterior = f->primeiro;
//                 anterior->dir->esq = anterior->esq;
//                 f->primeiro = anterior->dir;
//                 f->ultimo->dir = f->primeiro;
//                 x = anterior->data;
//                 delete anterior;
//                 ok = true;


//             }
//         }

// void destroi(File &f){
//             while(!f->vazia()){
//                 int x;
//                 bool ok;
//                 f->retira(x,ok);
//             }
//         }