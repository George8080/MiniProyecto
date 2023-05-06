#include "VectorList.h"

VectorList::VectorList() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

VectorList::~VectorList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    //delete current;
    head = nullptr;
    tail = nullptr;
    count = 0;
}

int VectorList::at(int rank){
    try{
        if(rank >= count || rank < 0)
            throw "Rank pedido esta sobre los elementos pedidos: no hay elemento para retornar.";
        if(rank == (count-1))
            return tail->data;
        Node* temp = head;
        for (int i = 0; i < rank; ++i){
            temp = temp->next;
        }
        int aux = temp->data;
        temp = nullptr;
        delete temp;
        return aux;
    } catch(const char* message) {
        cerr << message << endl;
        exit(EXIT_FAILURE);
    }
}

int VectorList::size(){
    return count;
}

void VectorList::insert(int rank, int data){
    try{
        if(rank > count || rank < 0)
            throw "Rank pedido esta sobre los elementos pedidos: no se puede ingresar elemento.";
        Node* add;
        add = new Node(data,nullptr);
        if(count == 0){
            head = add;
            tail = add;
        }
        else if(rank == 0){
            add->next = this->head;
            head = add;
        }
        else if(rank == count){
            tail->next = add;
            if(head->next == nullptr) head->next = add;
            tail = add;
        }
        else{
            Node* temp = head;
            for (int i = 0; i < rank-1; ++i){
                temp = temp->next;
            }
            add->next = temp->next;
            temp->next = add;
        }
        count++;
        add = nullptr;
        delete add;
    } catch(const char* message) {
        cerr << message << endl;
    }
}

void VectorList::insert_left(int data) {
    this->insert(0,data);
}

void VectorList::insert_right(int data) {
    this->insert(count,data);
}

bool VectorList::empty() {
    return count==0;
}

bool VectorList::find(int val) {
    Node* aux = head;
    while(aux != nullptr){
        if(aux->data == val){
            aux = nullptr;
            delete aux;
            return true;
        }
        aux = aux->next;
    }
    aux = nullptr;
    delete aux;
    return false;
}