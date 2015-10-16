#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int primes[26] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 59, 61, 67, 71, 73, 79, 83, 89};

int isPrime(int x)
{
    for(int i = 0; i < 26; i++){
        if(primes[i] == x){
            return 1;
        }
    }
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    int answers[n];
    for(int t = 0; t < n; t ++){
        char input[90];
        scanf("%s", input);
        int length = strlen(input);
        if(isPrime(length)){
            answers[t] = length;
            //continue;
        }
        for(int i = 1; i <= length; i++){
            if(length % i == 0){
                int j = i;
                for(; j < length; j++){
                    if(input[j] != input[j % i]){
                        break;
                    }
                }
                if( j == length){
                    answers[t] = i;
                    break;
                }
            }
        }
    }
    int t = 0;
    for(; t < n - 1; t ++){
        printf("%d\n\n", answers[t]);
    }
    printf("%d\n", answers[n - 1]);
    return 0;
}
