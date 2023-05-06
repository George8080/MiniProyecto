#include "VectorADT.h"

#ifndef VECTORLIST_H
#define VECTORLIST_H


using namespace std;

class VectorList : public VectorADT {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data, Node* next = nullptr) {
            this->data = data;
            this->next = next;
        }
    };
    Node* head;
    Node* tail;
    int count;

public:
    VectorList();
    ~VectorList();
    int at(int rank);
    int size();
    void insert(int rank,int data);
    void insert_left(int data);
    void insert_right(int data);
    bool empty();
    bool find(int val);
};


#endif