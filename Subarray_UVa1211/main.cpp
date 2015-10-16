#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int trashold, length;

int solve(int* sequence);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(scanf("%d%d", &length, &trashold) == 2){
        int* read = new int[length];
        for(int i = 0; i < length; i++){
            cin >> read[i];
        }
        printf("%d\n", solve(read));
    }
    return 0;
}

int solve(int* sequence)
{
    int noter[100000];
    memset(noter, 0, 100000);
    int j = 0, minmum = 10000000;
    int sum = sequence[0];
    for(int i = 1; i <= length; i++){
        if(sum >= trashold){
            while(i > j && (sum - sequence[j] >= trashold)){ //shrink the size
                sum -= sequence[j];
                j++;
            }
            noter[i - 1] = i - j;
        }else{
            noter[i - 1] = 0;
        }
        sum += sequence[i];
    }
    for(int i = 0; i < length; i++){
        if(noter[i] < minmum && noter[i] > 0){
            minmum = noter[i];
        }
    }
    return minmum == 10000000 ? 0 : minmum;
}
