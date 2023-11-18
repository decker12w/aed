struct Node {
    int data;
    Node* prox;
};

class Pilha {
private:
    Node* top;

public:
    Pilha() : top(nullptr) {}

    ~Pilha() {
        while (!vazia()) {
            int x;
            desempilha(x);
        }
    }

    bool vazia() const {
        return (top == nullptr);
    }

    bool empilha(int x) {
        Node* ptr = new Node();
        ptr->data = x;

        ptr->prox = top;
        top = ptr;
        return true;
    }

    bool desempilha(int &x) {
        if (vazia()) {
            return false;
        }

        Node* remove = top;
        x = remove->data;
        top = remove->prox;
        
        return true;
    }

    bool topo(int &x) const {
        if (vazia()) {
            return false;
        }
        x = top->data;
        return true;
    }
};
