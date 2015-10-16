#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>
#define length 19

using namespace std;

int price[20] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30, 35, 37, 40, 42, 46, 46, 49, 50, 55};

int hode[100];

int cutRod(int n);

int main()
{
    memset(hode, 0, 100);
    cout << "max = " << cutRod(length);
    return 0;
}

int cutRod(int n)
{
    if(n == 0)
        return 0;
    int q = -1000;
    for(int i = 1; i <= n; i++)
        q = q > (price[i] + cutRod(n - i)) ? q : price[i] + cutRod(n - i);
    return q;
}


