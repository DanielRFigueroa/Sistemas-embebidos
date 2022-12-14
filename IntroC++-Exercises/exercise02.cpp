
// =================================================================
//
// File: exercise02.cpp
// Author(s):
// Description: This file contains the code that performs the sum of
//				all prime numbers less than or equal to MAXIMUM. The 
//				time this implementation takes will be used as the 
//				basis to calculate the improvement obtained with 
//				parallel technologies.
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "utils.h"

#define MAXIMUM 1000000 //1e6

using namespace std;

bool isPrimeNumber(int x) {
	int i;

	if (x < 2) {
		return false;
	}
	for (i = 2; i < sqrt(x); i ++) {
		if (x % i == 0) {
			return false;
		}
	}

	return true;
}

double sumPrimeNumbers(int maximum) {
	double acum = 0;
	int i;

	for (i = 0; i <= maximum; i ++) {
		if (isPrimeNumber(i)) {
			acum = acum + i;
		}
	}

	return acum;
}

int main(int argc, char* argv[]) {
	int i;
	double ms, result;

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();

		result = sumPrimeNumbers(MAXIMUM);

		ms += stop_timer();
	}
	cout << "result = " << fixed << setprecision(0) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	return 0;
}