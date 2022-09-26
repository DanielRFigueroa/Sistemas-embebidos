// =================================================================
//
// File: exercise04.cpp
// Author(s): Diego Alfonso Ramirez Montes
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

double eulerSum(int lim){
	int i;
	double appPi;
	
	for(i = 1; i < lim; i++){
		appPi += pow(pow(i,2),-1);
		
	}
	
	appPi = sqrt(appPi * 6);
	return appPi;

}

int main(int argc, char* argv[]) {
	double result;
	double ms;

	result = 0;

	cout << "Starting..." << endl;
	ms = 0;
	for (int i = 0; i < N; i++) {
		start_timer();

		result = eulerSum(LIMIT);

		ms += stop_timer();
	}
	cout << "result = " << setprecision(5) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	return 0;
}