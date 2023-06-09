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
        NodeSummary(int b) {
            total_capacity = b;
            total_size = 0;
            left_child = nullptr;
            right_child = nullptr;
            left_arr = nullptr;
            right_arr = nullptr;
        }
        /*
        Este metodo recibe un entero s que es el tamaño del nodo 
        actual que se tiene.
        Tambien recibe la capacidad máxima del arreglo y un nodo
        arreglo 
        */
        void generateTree(int s, int max, Node* &arr){
            if(arr == nullptr) return;
            if(s == max*2){
                this->left_arr = arr;
                this->total_size += arr->num_elements;
                arr = arr->next;
                this->right_arr = arr;
                if(arr != nullptr){
                    this->total_size += arr->num_elements;
                    arr = arr->next;
                }
            }else{
                this->left_child = new NodeSummary(s/2);
                (this->left_child)->generateTree(s/2,max,arr);
                this->total_size = (this->left_child)->total_size;
                if(arr != nullptr) {
                    this->right_child = new NodeSummary(s/2);
                    (this->right_child)->generateTree(s/2,max,arr);
                    this->total_size += (this->right_child)->total_size;
                }
            }
        }
    };
    int maxSize;
    int arrSize;
    int num_elements;
    int num_arrays;
    NodeSummary* root;
    Node* head;

public:
    ListArr(int b);
    ~ListArr();
    int size();
    void insert_left(int v);
    void insert_right(int v);
    void insert(int v, int i);
    void print();
    bool find(int v);
    void createTree();
};


#endif