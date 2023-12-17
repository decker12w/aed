/*Questão 2. (3 pontos) Considere o Tipo Abstrato de Dados Pilha implementado através de uma lista duplamente encadeada, circular, com nó
Header, segundo os diagramas abaixo. No diagrama a esquerda, a Pilha P está vazia. No diagrama a direita, a pilha contém 3 elementos – A, B e
C. Se seu primeiro nome começa com as letras A, B, .. M, considere que A está no topo e a sequência de entrada na pilha foi C, B, A. Se seu
primeiro nome começa com as letras N, O, ... Z, considere que C está no topo e a sequência de entrada na pilha foi A, B, C. Implemente as
operações:
• Boolean Vazia(variável por referência P do tipo Pilha) // retorna True se a Pilha não tiver nenhum elemento; falso caso contrário.
• Empilha (variável por referência P do tipo Pilha, variável X do tipo Elemento) /* insere 1 elemento na Pilha P. Desconsidere a possibilidade de
a Pilha estar cheia */
Node* top;

bool vazia(P* pilha){
    return (pilha->header->dir == pilha->header->esq)
}

bool empilha(P* pilha, int x){
    if(vazia()){
        return false;
    }
    else {
        Node* novo = new Node();
        Node* atual = pilha->header->dir;
        Node* ant;
        while (atual!=hedader)
        {
            ant = atual;
            atual = atual->dir;
        }
        
        ant->dir = novo;
        novo->esq = ant;
        novo->dir = header;
        top = novo;
    }
}