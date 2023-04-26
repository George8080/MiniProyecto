#include "ListArrADT.h"

#ifndef LISTARR_H
#define LISTARR_H


using namespace std;

class ListArr : public ListArrADT {
private:
     struct Node {
        int *arr;
        int b;
        int num_elements;
        Node *next;
        
        Node(int b) {
            this->b = b;
            num_elements = 0;
            arr = new int[b];
            next = nullptr;
        }
        
        ~Node() {
            delete[] arr;
        }
    };

    struct NodeSummary {
        int total_capacity;
        int total_size;
        NodeSummary* left_child;
        NodeSummary* right_child;
        Node* left_arr;
        Node* right_arr;
    };

    int b;
    int num_elements;
    NodeSummary* root;

public:
    ListArr();
    ~ListArr();
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
};


#endif