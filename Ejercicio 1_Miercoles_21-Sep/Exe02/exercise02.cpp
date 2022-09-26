// =================================================================
//
// File: exercise02.cpp
// Author(s): Diego Alfonso Ramirez Montes
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

bool fact(int a){
	int f = 1;
	for(int i = 1; i <= a; i++){
		f = f*i;
		
	}
	return f;

}

bool comp(int a){
	float pi = 3.14159265358979323846;
	if(floor(pow(cos(pi*((fact(a-1)+1)/a)),2)) == 1){
		return 1;
		
	}
	return 0;
	
}

double sumP(int size){
	double acum;
	int i;
	
	acum = 0;
	for(i = 2; i < size; i++){
		if(comp(i)){
			acum += i;
			
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

		result = sumP(MAXIMUM);

		ms += stop_timer();
	}
	cout << "result = " << fixed << setprecision(0) << result << "\n";
	cout << "avg time = " << setprecision(5) << (ms / N) << " ms" << endl;

	return 0;
}