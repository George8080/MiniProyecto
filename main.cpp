#include <iostream>
#include "ListArr.h"
#include <chrono>
#include <random>

using namespace std;

int main(){
	random_device rd;

	const unsigned long long n = 100;
	const unsigned long long b = 1;
	const long long maxRandValue = 3;
	long long varValueLeft = 0, varValueRight = 0;
	double total_time=0;
	
	ListArr *la = new ListArr(b);
	
	cout << "\nInsert left: \n" << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		//la->insert_left(rd()%maxRandValue);
		la->insert_left(varValueLeft++);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}
	
	cout << "Tiempo total de la operacion: " << total_time << " nanosegundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/n << " nanosegundos" << endl;
	
	cout << "\nInsert right: " << endl;
	for(unsigned long long i=0; i<n/2 ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		//la->insert_right(rd()%maxRandValue);
		la->insert_right(varValueRight--);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}

	cout << "Tiempo total de la operacion: " << total_time << " nanosegundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/n << " nanosegundos" << endl;
	
	cout << "\nFind: \n" << endl;
	for(unsigned long long i=0; i<n ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		la->find(rd()%(maxRandValue*2));
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}
	cout << "Tiempo total de la operacion: " << total_time << " nanosegundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/n << " nanosegundos" << endl;


	cout << "\nPrint: \n" << endl;
	if(true){
		auto start_time= chrono::high_resolution_clock::now();
		la->print();
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}
	cout << "Tiempo total de la operacion: " << total_time << " nanosegundos" << endl;
	delete la;

	return 0;
};