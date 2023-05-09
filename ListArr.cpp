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
	(this->root)->right_arr = nullptr;
	this->num_arrays = 1;
}


////////////	Destructor del Arbol	////////////
ListArr::~ListArr(){
	/* 
	En este metodo se recorre todo el arbol haciendo
	uso de stacks para recursivamente ir tomando los
	nodos hijos de izquierda a derecha mientras los 
	nodos padres se van borrando*/

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
	/* 
	En este metodo para crear un arbol primero se borra el
	arbol de los nodos resumenes
	Luego se crea un puntero a la cabeza y tambien una nueva
	raiz con el tamaño maximo actual 
	Luego a partir de estas raices se crea un arbol
	Primero borro el arbol, pero solo los nodos resumenes
	creo un puntero a la cabeza se crea una nueva raiz con 
	el tamaño maximo actual y luego partir estas raices crea
	un arbol */
	queue<NodeSummary*> nodos;
	nodos.push(root);
	while(nodos.size()>0){
		if((nodos.front())!=nullptr){
			nodos.push((nodos.front())->left_child);
			nodos.push((nodos.front())->right_child);
		}
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
	/* 
	Se crea un nodo resumen que apunta a 
	la raiz, de esta manera a medida que
	va recorriendo los nodos (desde la raiz)
	va sumando al contador 
	*/

	NodeSummary* aux = root;
	aux->total_size++;
	Node* array = nullptr;
	while(aux->left_child != nullptr){
		aux = aux->left_child;
		aux->total_size++;
	}
	array = aux->left_arr;
	/*
	Se asegura que no haya ningun espacio vacio a 
	la derecha del arreglo para cuando se quiera
	insertar un elemento a la izquierda, se pueda
	garantizar que se esta haciendo uso eficiente 
	de la memoria y el espacio del arreglo
	*/

	if(array->num_elements < array->b){
		int temp = v;
		for (int i = 0; i < array->num_elements; ++i){
			swap(temp,array->arr[i]);
		}
		array->arr[array->num_elements] = temp;
		array->num_elements++;
		this->num_elements++;
	}
	/*
	En el caso de que este todo el nodo lleno se debe
	crear un nuevo nodo a la izquierda del head, el
	cual almacenara el nuevo elemento y se volvera
	el nuevo head del arbol; tambien se llamara a
	createTree para actualizarlo
	*/
	else{
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
	/*
	Se borran los elementos de memoria dinamica
	para evitar malgastar la memoria RAM del
	dispositivo.
	*/
	array = nullptr;
	delete array;
	aux = nullptr;
	delete aux;
}


////////////	Insertar al final	////////////
void ListArr::insert_right(int v){
	/*
	Se crea un nodo resumen que apunta a 
	la raiz, de esta manera a medida que
	va recorriendo los nodos (desde la raiz
	hasta lo mas a la derecha posible) va 
	sumando al contador 
	*/
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

	/*
	Si es que aun queda un espacio en el
	arreglo entonces añadir el elemento y
	sumarselo a su contador, si es que no
	entonces crear un nuevo arreglo a la
	derecha que almacene el valor y se sume
	uno a su contador; tambien debe 
	actualizar el arbol con createTree
	*/
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
	/*
	Si la posicion esta fuera de los limites del
	arbol entonces tirar un error al usuario
	*/
	try{	
		if(0 > pos || num_elements < pos)
			throw "ERROR: Indice esta fuera del arreglo!!";
		/* 
		Se crea un nodo resumen que apunta a 
		la raiz, de esta manera a medida que
		va recorriendo los nodos (desde la raiz)
		va sumando al contador, y un nodo arreglo
		para recibir el arreglo en el cual se
		añadira el elemento
		*/
		NodeSummary* aux = root;
		Node* auxNode;
		int i = pos;
		(aux->total_size)++;
		/*
		Mientras no llegen a los arreglos ir recorriendo
		el arbol, si la posicion esta dentro del nodo hijo
		de la derecha o si no existe izquierad recorrer 
		este, si es que no entonces recorrer izquierda
		*/
		while(aux->left_child != nullptr || aux->right_child != nullptr){
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
		if(i < (aux->left_arr)->num_elements){
			auxNode = aux->left_arr;
		}else{
			if(aux->right_arr == nullptr)
				auxNode = aux->left_arr;
			else{
				i = i - (aux->left_arr)->num_elements;
				auxNode = aux->right_arr;
			}
		}
		/*
		Una vez llegado al arreglo se debe generar
		un espacio para ingresar el valor, moviendo 
		los elementos ubicados en la posicion buscada
		en adelante un espacio a la derecha
		*/
		int temp = v;
		for (int j = i; j < auxNode->num_elements; ++j){
			swap(temp,auxNode->arr[j]);
		}
		/*
		Si al final falta espacio crear un nuevo nodo
		que almacene el valor faltante y se actualice
		el arbol, si no finalizar el movimiento anterior.
		*/
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
		/*
		Borrar los elementos de memoria dinamica
		para evitar problemas con la RAM
		*/
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
	/*
	Se crea un puntero a la cabeza, el cual se
	ira actualizando con los siguientes nodos,
	y por cada nodo que recorra imprimir todos
	los valores del arreglo.
	*/
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

	/* Esta funcion recibe como parametro un entero v que procede
   		a buscar en el arreglo
 	*/
bool ListArr::find(int v){
	/* Se crea un nodo auxiliario que recibe el valor de la cabeza
	de los nodos arreglo
		Mientras este valor exista se busca en el arreglo si el
		entero v se encuentra entre los elementos ingresados, si
		se encuentra se retorna verdadero, de lo contrario

	*/
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