#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    float number, total = 0;
    for(int i = 0; i < 12; i++){
        scanf("%f", &number);
        total += number;
    }
    total /= 12;
    printf("$%.2f", total);
    cout << endl;
    return 0;
}
