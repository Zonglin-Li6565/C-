//============================================================================
// Name        : Tri_Tiling.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 31
using namespace std;

int solve(int length, int status, int* count);

int main() {
	int* count = new int[2 * MAX];
	for(int i = 0 ; i < 4 * MAX; i++) {
		count[i] = -1;
	}
	count[2] = 3;
	count[MAX * 1 + 2] = 1;
	int input;
	for(scanf("%d", &input); input != -1; scanf("%d", &input)) {
		printf("%d\n", solve(input, 0, count));
	}
	return 0;
}

int solve(int length, int status, int* count) {
	int* countat = count + MAX * status + length;
	if(length == 0)
		return 1;
	if(*countat != -1) {
		return *countat;
	}
	if(length % 2 == 1) {
		*countat = 0;
		return 0;
	}
	switch(status) {
	case 0: {
		*countat = solve(length - 2, 0, count) * 3 +
				solve(length - 2, 1, count) * 2;
		break;
	}
	case 1: {
		*countat = solve(length - 2, 0, count) + solve(length - 2, 1, count);
		break;
	}
	}
	return *countat;
}


