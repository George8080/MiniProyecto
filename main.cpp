#include <iostream>
#include "ListArr.h"
#include "VectorList.h"
#include "VectorArray.h"
#include <chrono>
#include <random>

using namespace std;

int main(){
	random_device rd;

	const unsigned long long n = 1000000;
	const unsigned long long b = 1;
	const long long maxRandValue = 3;
	double total_time=0;
	
	////////////////////////////	ListArr 	////////////////////////////
	cout << "\n-LIST ARRAY:" << endl;
	ListArr *la = new ListArr(b);
	
	cout << "\nInsert left: " << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		//cout << i << ' ';
		auto start_time= chrono::high_resolution_clock::now();
		la->insert_left(rd()%maxRandValue);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;
	}
	
	cout << "\nTiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;

	cout << "\nInsert right: " << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		//cout << i << ' ';
		auto start_time= chrono::high_resolution_clock::now();
		la->insert_right(rd()%maxRandValue);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;
	}

	cout << "\nTiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;

	cout << "\nFind: " << endl;
	for(unsigned long long i=0; i<n ; ++i){
		//cout << i << ' ';
		auto start_time= chrono::high_resolution_clock::now();
		la->find(rd()%(maxRandValue*2));
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;
	}
	cout << "\nTiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;
	delete la;


	////////////////////////////	VectorArr 	////////////////////////////
	cout << "\n\n-VECTOR ARRAY:" << endl;
	VectorArray *va = new VectorArray(b);
	
	cout << "\nInsert left: \n" << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		va->insert_left(rd()%maxRandValue);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;
	}
	
	cout << "Tiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;
	
	cout << "\nInsert right: \n" << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		va->insert_right(rd()%maxRandValue);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;
	}

	cout << "Tiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;
	
	cout << "\nFind: \n" << endl;
	for(unsigned long long i=0; i<n ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		va->find(rd()%(maxRandValue*2));
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}
	cout << "Tiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;
	delete va;


	////////////////////////////	VectorList	////////////////////////////
	cout << "\n\n-VECTOR LIST:" << endl;
	VectorList *vl = new VectorList();
	
	cout << "\nInsert left: \n" << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		vl->insert_left(rd()%maxRandValue);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}
	
	cout << "Tiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;
	
	cout << "\nInsert right: \n" << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		vl->insert_right(rd()%maxRandValue);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}

	cout << "Tiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	total_time = 0;
	
	cout << "\nFind: \n" << endl;
	for(unsigned long long i=0; i<n ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		vl->find(rd()%(maxRandValue*2));
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}
	cout << "Tiempo total de la operacion: " << total_time / 1e9 << " segundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/(n/2) << " nanosegundos" << endl;
	delete vl;


	return 0;
};