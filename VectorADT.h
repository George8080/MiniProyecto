#ifndef VECTORADT_H
#define VECTORADT_H   
#include<iostream>

using namespace std;

class VectorADT{
public:
    virtual int at(int) = 0;
    virtual int size() = 0;
    virtual void insert(int,int) = 0;
    virtual void insert_left(int) = 0;
    virtual void insert_right(int) = 0;
    virtual bool empty() = 0;
    virtual bool find(int) = 0;
};

#endif