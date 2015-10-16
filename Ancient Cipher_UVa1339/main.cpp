#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

int isSame(char* encrypted, char* original, int length){
    int counterE[26];
    int counterO[26];
    int sublength = 0;
    memset(counterE, 0, sizeof(counterE));
    memset(counterO, 0, sizeof(counterO));
    for(int i = 0; i < length; i++){
        counterE[encrypted[i] - 'A']++;
        counterO[original[i] - 'A']++;
    }
    bool found = false;
    for(int i = 0; i < 26; i++){
        found = false;
        if(counterE[i] != 0){
            for(int j = 0; j < 26; j++){
                if(counterO[j] == counterE[i]){
                    found = true;
                    counterO[j] = 0;
                    break;
                }
            }
            if(!found){
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char encrypted[110];
    char original[110];
    int length_0, length_1;
    while(scanf("%s%s", encrypted, original) == 2){
        length_0 = strlen(encrypted);
        length_1 = strlen(original);
        if(isSame(encrypted, original, length_0)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
