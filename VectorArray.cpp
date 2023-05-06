#include "VectorArray.h"

VectorArray::VectorArray(int capacity) {
    this->capacity = capacity;
    this->n = 0;
    this->array = new int[capacity];
}

VectorArray::~VectorArray() {
    delete[] array;
}

int VectorArray::at(int rank){
	try{
		if(rank >= n || rank < 0)
			throw "Rank pedido esta sobre los elementos pedidos: no hay elemento para retornar.";
		return array[rank];
	} catch(const char* message) {
        cerr << message << endl;
        exit(EXIT_FAILURE);
    }
}

int VectorArray::size(){
	return n;
}

void VectorArray::insert(int rank,int data){
	try{
		if(rank > n || rank < 0)
			throw "Rank pedido esta sobre los elementos pedidos: no se puede ingresar elemento.";
		if( this->size() == capacity ){
	        capacity = capacity * 2;
	        int* aux;
	        aux = new int[capacity];
	        for (int i = 0; i < n; ++i){
	            aux[i] = array[i];
	        }
	        delete[] array;
	        array = new int[capacity];
	        for (int i = 0; i < n; ++i){
	            array[i] = aux[i];
	        }
	        delete[] aux;
	    }
	    for (int i = n; i > rank; --i){    	
	    	array[i]=array[i-1];
	    }
	    array[rank] = data;
	    n++;
	} catch(const char* message) {
        cerr << message << endl;
    }
}

void VectorArray::insert_left(int data) {
	this->insert(0,data);
}

void VectorArray::insert_right(int data) {
	this->insert(n,data);
}

bool VectorArray::empty() {
	return n==0;
}

bool VectorArray::find(int val) {
	for (int i = 0; i < n; ++i)
		if(array[i] == val) return true;
	return false;
}