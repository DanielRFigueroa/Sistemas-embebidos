// =================================================================
//
// File: exercise01.cpp
// Author(s):	Javier Suarez Duran - A01707380
//				Daniel Rodríguez Figueroa - A01612889 
// Description: This file contains the code to count the number of
//				even numbers within an array. The time this implementation
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
#include <climits>
#include <algorithm>
#include "utils.h"

const int SIZE = 100000000; //1e8

using namespace std;

// implement your code here
double countEvens(int *array, int size) {
	double acum;
	int i;

	acum = 0;

	for (int i = 0; i < size; i ++) {
		if (array[i] % 2 == 0) {
			acum ++;
		}
	}

	return acum;
}

int main(int argc, char* argv[]) {
	int *a;
	double ms, result;

	a = new int[SIZE];
	fill_array(a, SIZE);
	display_array("a", a);

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();

		result = countEvens(a, SIZE);

		ms += stop_timer();
	}
	cout << "result = " << fixed << setprecision(0) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	delete [] a;
	return 0;
}
