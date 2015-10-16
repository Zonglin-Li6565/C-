#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    double answers[n];
    double constants[15];
    constants[2] = 12.010;  //C
    constants[7] = 1.008;   //H
    constants[13] = 14.010; //N
    constants[14] = 16.000; //O
    for(int t = 0; t < n; t++){
        double mass = 0.0;
        char String[90];
        scanf("%s", String);
        int length = strlen(String);
        for(int i = 0; i < length; i++){
            if(isalpha(String[i])){
                if((i + 1) < length && isdigit(String[i + 1])){
                    double singleMass = constants[String[i] - 65];
                    int number = 0;
                    while((i + 1) < length && isdigit(String[i + 1])){
                        number = number * 10 + String[i + 1] - 48;
                        i++;
                    }
                    mass += singleMass * number;
                    continue;
                }
                if((i + 1) == length || isalpha(String[i + 1])){
                    mass += (constants[String[i] - 65]);
                    continue;
                }
            }
        }
        answers[t] = mass;
    }
    for(int i = 0; i < n; i++){
        printf("%0.3f\n", answers[i]);
    }
    return 0;
}
