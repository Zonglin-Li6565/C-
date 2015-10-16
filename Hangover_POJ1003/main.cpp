#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    float input;
    scanf("%f", &input);
    while(input > 0.0){
        int i = 1;
        float length = 0.0;
        for(; length < input; i++){
            length += 1.0 / (i + 1.0);
        }
        i--;
        printf("%d card(s)\n", i);
        scanf("%f", &input);
    }
    return 0;
}
