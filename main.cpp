#include <iostream>
#include "ListArr.h"
#include <chrono>
#include <random>

using namespace std;

int main(){
//	random_device rd;

	const unsigned long long n = 10;
	const long long maxRandValue = 2;
	double total_time=0;
	
	ListArr *la = new ListArr(20);

	cout << "\nInsert left: \n" << endl;
	for(unsigned long long i=0; i<n ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		la->insert_left(5);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}

	cout << "Tiempo total de la operacion: " << total_time << " nanosegundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/n << " nanosegundos" << endl;

	cout << "\nInsert right: " << endl;
	for(unsigned long long i=0; i<n ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		la->insert_right(5);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}

	cout << "Tiempo total de la operacion: " << total_time << " nanosegundos" << endl;
	cout << "Tiempo promedio de la operacion: " << total_time/n << " nanosegundos" << endl;

	cout << "\nFind: \n" << endl;
	for(unsigned long long i=0; i<n ; ++i){
		auto start_time= chrono::high_resolution_clock::now();
		la->find(5);
		auto end_time = chrono::high_resolution_clock::now();
		auto duration_time = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
		total_time += duration_time;

	}

	cout << "Tiempo promedio de la operacion: " << total_time/n << " nanosegundos" << endl;

	delete la;

	return 0;
};