// =================================================================
//
// File: exercise04.cpp
// Author(s):
// Description: This file implements the PI approximation using the
//				series proposed by Euler.
//				pi = sqrt ( 6 * sumatoria(i = 1-N) (1 / i^2) )
//				The time this implementation takes will be used as
//				the basis to calculate the improvement obtained with
//				parallel technologies.
//
// Copyright (c) 2022 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include "utils.h"

const int LIMIT = 100000000; //1e8

using namespace std;

double pi_WithEuler(int limit) {
	double pi, sum = 0;

	for (int i = 1; i < limit; i ++) {
		sum += (1 / pow(i, 2));
	}

	pi = sqrt(6 * sum); 

	return pi;
}

int main(int argc, char* argv[]) {
	double ms, result;

	result = 0;

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();

		result = pi_WithEuler(LIMIT);

		ms += stop_timer();
	}
	cout << "result = " << setprecision(5) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	return 0;
}