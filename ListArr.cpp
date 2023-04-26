#include "ListArr.h"

using namespace std;

ListArr::ListArr(int b){
	this->b = b;
	this->num_elements = 0;

}

ListArr::~ListArr(){
	
}

int ListArr::size(){
	return this->num_elements;
}
void ListArr::insert_left(int v){
	NodeSummary* aux = root;
	Node* array = nullptr;
	while(aux->left_child != nullptr){
		aux = aux->left_child;
	}
	array = aux->left_arr;
	// FALTA AGREGAR ELEMENTO
}
void ListArr::insert_right(int v){
	NodeSummary* aux = root;
	Node* array = nullptr;
	while(aux->left_child != nullptr || aux->right_child != nullptr){
		if(aux->right_child != nullptr)
			aux = aux->right_child;
		else
			aux = aux->left_child;
	}
	if(aux->right_arr != nullptr)
		array = aux->right_arr;
	else
		array = aux->left_arr;
	// FALTA AGREGAR ELEMENTO
}
void ListArr::insert(int v, int i){

}
void ListArr::print(){
	NodeSummary* aux = root;
	Node* array = nullptr;
	while(aux->left_child != nullptr){
		aux = aux->left_child;
	}
	array = aux->left_arr;
	while(true){
		for (int i = 0; i < array->num_elements; ++i){
			cout << b[i] << " ";
		}
		if(array->next==nullptr) break;
		array = array->next;
	}
	cout << endl;
}

bool ListArr::find(int v){
	NodeSummary* aux = root;
	Node* array = nullptr;
	while(aux->left_child != nullptr){
		aux = aux->left_child;
	}
	array = aux->left_arr;
	while(true){
		for (int i = 0; i < array->num_elements; ++i){
			if(b[i] == v) return true;
		}
		if(array->next==nullptr) break;
		array = array->next;
	}
	return false;
}