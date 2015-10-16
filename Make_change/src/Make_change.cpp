//============================================================================
// Name        : Make_change.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int x[101];
	fill(&x[0], &x[99], 0);
	x[0] = 1;
	for(int i = 5; i < 101; i++) {
		x[i] = (x[i - 5] || x[i - 8]);
	}
	for(int i = 101; i > 0; i--) {
		if(x[i] == 0) {
			cout << i;
			break;
		}
	}
	return 0;
}
