//============================================================================
// Name        : Fibonacci.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	printf("which fibonacci number you want?\n");
	scanf("%d", &n);
	int* table = new int[n];
	if(n <= 2)
	{
		printf("1");
		return 0;
	}
	table[0] = table[1] = 1;
	for(int i = 2; i < n; i++)
	{
		table[i] = table[i - 1] + table[i - 2];
	}
	cout << table[n - 1];
	return 0;
}
