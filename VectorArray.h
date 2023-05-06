#include "VectorADT.h"

#ifndef VECTORARRAY_H
#define VECTORARRAY_H

class VectorArray : public VectorADT {
private:
    int* array;
    int capacity, n;
public:
    VectorArray(int capacity);
    ~VectorArray();
    int at(int rank);
    int size();
    void insert(int rank,int data);
    void insert_left(int data);
    void insert_right(int data);
    bool empty();
    bool find(int val);
};


#endif