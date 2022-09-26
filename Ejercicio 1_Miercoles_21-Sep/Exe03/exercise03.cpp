// =================================================================
//
// File: exercise03.cpp
// Author(s): Diego Alfonso Ramirez Montes
// Description: This file contains the code that implements the
//				enumeration sort algorithm. The time this implementation
//				takes ill be used as the basis to calculate the
//				improvement obtained with parallel technologies.
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include "utils.h"

const int SIZE = 10000; //1e4

using namespace std;

void swap(int *a, int i, int j) {
  int aux = a[i];
  a[i] = a[j];
  a[j] = aux;
  
}

int* enumSort(int *a, int size) {
	int *b = new int[size];

	memcpy(b, a, sizeof(int) * SIZE);

	for(int i = size - 1; i > 0; i --){
		for(int j = 0; j < i; j ++){
			if ((b[i] < b[j]) || ((b[i] == b[j]) && (i < j))) {
				swap(b, j, i);
				
			}
			
		}
		
	} 
	return b;
	
}

int main(int argc, char* argv[]) {
	int *a, *b;
	double ms;

	a = new int[SIZE];
	random_array(a, SIZE);
	display_array("before", a);

	cout << "Starting..." << endl;
	ms = 0;
	
	for(int i = 0; i < N; i++){
		start_timer();

		b = enumSort(a, SIZE);

		ms += stop_timer();
	}
	
	display_array("after", b);
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	delete [] a;
	return 0;
}