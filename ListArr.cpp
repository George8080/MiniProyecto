#include "ListArr.h"
#include <queue>
#include <cmath>
using namespace std;

////////////	Constructor del Arbol	////////////
ListArr::ListArr(int b){
	this->maxSize = b*2;
	this->arrSize = b;
	this->num_elements = 0;
	this->root = new NodeSummary(maxSize);
	this->head = new Node(arrSize);
	(this->root)->left_arr = head;
	this->num_arrays = 1;
}


////////////	Destructor del Arbol	////////////
ListArr::~ListArr(){
	queue<NodeSummary*> nodos;
	queue<Node*> arreglos;
	nodos.push(root);
	while(!nodos.empty()){
		if((nodos.front())->left_child!=nullptr)
			nodos.push((nodos.front())->left_child);
		if((nodos.front())->right_child!=nullptr)
			nodos.push((nodos.front())->right_child);

		if((nodos.front())->left_arr!=nullptr)
			arreglos.push((nodos.front())->left_arr);
		if((nodos.front())->right_arr!=nullptr)
			arreglos.push((nodos.front())->right_arr);
		/*if((nodos.front())!=nullptr){
			nodos.push((nodos.front())->left_child);
			nodos.push((nodos.front())->right_child);
			arreglos.push((nodos.front())->left_arr);
			arreglos.push((nodos.front())->right_arr);
		}*/

		NodeSummary* auxSum = nodos.front();
		nodos.pop();
		delete auxSum;
	}
	while(!arreglos.empty()){
		Node* auxNode = arreglos.front();
		arreglos.pop();
		delete auxNode;
	}
}


////////////	Crear arbol de nodos	////////////
void ListArr::createTree(){
	queue<NodeSummary*> nodos;
	nodos.push(root);
	while(nodos.size()>0){
		if((nodos.front())!=nullptr){
			nodos.push((nodos.front())->left_child);
			nodos.push((nodos.front())->right_child);
		}
		//if((nodos.front())->left_child!=nullptr)
		//	nodos.push((nodos.front())->left_child);
		//if((nodos.front())->right_child!=nullptr)
		//	nodos.push((nodos.front())->right_child);
		NodeSummary* auxSum;
		auxSum = nodos.front();
		nodos.pop();
		delete auxSum;
	}
	Node* arr = head;
	this->root = new NodeSummary(maxSize);
	root->generateTree(maxSize,arrSize,arr);
	arr = nullptr;
	delete arr;
}

////////////	Retornar tamaño		////////////
int ListArr::size(){
	return this->num_elements;
}


////////////	Insertar al inicio	////////////
void ListArr::insert_left(int v){
	NodeSummary* aux = root;
	aux->total_size++;
	Node* array = nullptr;
	while(aux->left_child != nullptr){
		aux = aux->left_child;
		aux->total_size++;
	}
	array = aux->left_arr;
	if(array->num_elements < array->b){
		int temp = v;
		for (int i = 0; i < array->num_elements; ++i){
			swap(temp,array->arr[i]);
		}
		array->arr[array->num_elements] = temp;
		array->num_elements++;
		this->num_elements++;
	}else{
		Node* extra = new Node(arrSize);
		extra->arr[0] = v;
		extra->num_elements++;
		this->num_elements++;
		extra->next = array;
		num_arrays++;
		if( num_arrays*arrSize > maxSize ) maxSize*=2;
		this->head = extra;
		this->createTree();
		extra = nullptr;
		delete extra;
	}
	array = nullptr;
	delete array;
	aux = nullptr;
	delete aux;
}


////////////	Insertar al final	////////////
void ListArr::insert_right(int v){
	NodeSummary* aux = root;
	aux->total_size++;
	Node* array = nullptr;
	while(aux->left_child != nullptr || aux->right_child != nullptr){
		if(aux->right_child != nullptr){
			aux = aux->right_child;
		}
		else{
			aux = aux->left_child;
		}
		aux->total_size++;
	}
	if(aux->right_arr != nullptr)
		array = aux->right_arr;
	else
		array = aux->left_arr;
	aux = nullptr;
	delete aux;

	if(array->num_elements < arrSize){
		array->arr[array->num_elements] = v;
		array->num_elements++;
		this->num_elements++;
	}else{
		Node* extra = new Node(arrSize);
		extra->arr[0] = v;
		extra->num_elements++;
		this->num_elements++;
		extra->next = array->next;
		num_arrays++;
		if( num_arrays*arrSize > maxSize ) maxSize*=2;
		array->next = extra;
		this->createTree();
		extra = nullptr;
		delete extra;
	}
	array = nullptr;
	delete array;
}

////////////	Insertar elemento en 'pos'	////////////
void ListArr::insert(int v, int pos){
	try{
		if(0 > pos || num_elements < pos)
			throw "ERROR: Indice esta fuera del arreglo!!";
		NodeSummary* aux = root;
		Node* auxNode;
		int i = pos;
		(aux->total_size)++;
		while(aux->left_arr == nullptr || aux->right_arr == nullptr){
			if(i < (aux->left_child)->total_size){
				aux = aux->left_child;
			}else{
				if(aux->right_child == nullptr){
					aux = aux->left_child;
				}
				else{
					i = i - (aux->left_child)->total_size;
					aux = aux->right_child;
				}
			}
			(aux->total_size)++;
		}

		if(aux->right_arr == nullptr){
			auxNode = aux->left_arr;
		}else{
			if(i < (aux->left_arr)->num_elements)
				auxNode = aux->left_arr;
			else{
				i = i - (aux->left_arr)->num_elements;
				auxNode = aux->right_arr;
			}
		}
		int temp = v;
		for (int j = i; j < auxNode->num_elements; ++j){
			swap(temp,auxNode->arr[j]);
		}
		if(auxNode->num_elements==auxNode->b){
			Node* extra = new Node(arrSize);
			extra->arr[0] = temp;
			extra->num_elements++;
			this->num_elements++;
			extra->next = auxNode->next;
			num_arrays++;
			if( num_arrays*arrSize > maxSize ) maxSize*=2;
			auxNode->next = extra;
			this->createTree();
			extra = nullptr;
			delete extra;
		}else{
			auxNode->arr[auxNode->num_elements] = temp;
			auxNode->num_elements++;
			this->num_elements++;
		}
		aux = nullptr;
		delete aux;
		auxNode = nullptr;
		delete auxNode;
	} catch(const char* message) {
        cerr << message << endl;
    }
}


////////////	Imprimir todos los elementos	////////////
void ListArr::print(){
	Node* array = head;
	while(array != nullptr){
		for (int i = 0; i < array->num_elements; ++i){
			cout << array->arr[i] << " ";
		}
		if(array->next==nullptr) break;
		array = array->next;
	}
	cout << endl;
}


////////////	Buscar si existe el entero 'v'	////////////
bool ListArr::find(int v){
	Node* array = head;
	while(array != nullptr){
		for (int i = 0; i < array->num_elements; ++i){
			if(array->arr[i] == v) return true;
		}
		if(array->next==nullptr) break;
		array = array->next;
	}
	return false;
}