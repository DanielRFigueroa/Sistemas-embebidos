// =================================================================
//
// File: exercise03.cpp
// Author(s):
// Description: This file contains the code that implements the
//				enumeration sort algorithm. The time this implementation
//				takes will be used as the basis to calculate the
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

void swap(int *A, int i, int j) {
  int aux = A[i];
  A[i] = A[j];
  A[j] = aux;
}

int* enumerationSort(int *A, int size) {
	int *B = new int[size];

	memcpy(B, A, sizeof(int) * SIZE);

	for (int i = size - 1; i > 0; i --) {
		for (int j = 0; j < i; j ++) {
			if ((B[i] < B[j]) || ((B[i] == B[j]) && (i < j))) {
				swap(B, j, i);
			}
		}
	} 

	return B;
}

int main(int argc, char* argv[]) {
	int *a;
	double ms;

	a = new int[SIZE];
	random_array(a, SIZE);
	display_array("before", a);

	cout << "Starting..." << endl;
	ms = 0;

	int *b;

	for (int i = 0; i < N; i++) {
		start_timer();

		b = enumerationSort(a, SIZE);

		ms += stop_timer();
	}
	display_array("after", b);
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	delete [] a;
	return 0;
}