#include <iostream>

struct Node {
    int data;
    Node* next;
};

using NodePtr = Node*;

void removeOne(NodePtr& L, int x, bool& ok) {
    Node* current = L;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            ok = true;
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                L = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }

    ok = false;
}

void removeAll(NodePtr& L, int x, bool& ok) {
    Node* current = L;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data == x) {
            ok = true;
            if (previous != nullptr) {
                previous->next = current->next;
                delete current;
                current = previous->next;
            } else {
                Node* temp = current;
                L = current->next;
                delete temp;
                current = L;
            }
        } else {
            previous = current;
            current = current->next;
        }
    }

    if (!ok) {
        ok = false;
    }

    struct Node {
    int Info;
    Node* Next;
};

using NodePtr = Node*;

void Remove_1(NodePtr& L, int X, bool& Ok) {
    if (L == nullptr) {
        Ok = false; // caso 1: lista vazia
    } else if (L->Next == nullptr && X == L->Info) {
        delete L;
        L = nullptr;
        Ok = true; // caso 2: X está em L e é o único elemento da lista
    } else {
        NodePtr PAux, Ant;
        Ant = nullptr;
        PAux = L;

        while (PAux != nullptr && PAux->Info != X) {
            Ant = PAux;
            PAux = PAux->Next;
        }

        if (PAux != nullptr && PAux->Info == X) {
            if (PAux == L) {
                L = L->Next; // caso 3: removendo X do primeiro elemento da lista com vários elementos
                delete PAux;
            } else {
                Ant->Next = PAux->Next; // caso 4: remove X do meio ou do final da lista
                delete PAux;
            }
            Ok = true;
        } else {
            Ok = false;
        }
    }
}

void RemoveTodos(NodePtr& L, elemento X, bool& Ok) {
    bool RemoveuPeloMenosUm = false;
    
    do {
        RemoveUm(L, X, Ok);
        if (Ok == true) {
            RemoveuPeloMenosUm = true;
        }
    } while (Ok == true);
    
    Ok = RemoveuPeloMenosUm;
}


}
