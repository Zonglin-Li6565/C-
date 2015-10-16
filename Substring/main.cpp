#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char stringA[100010];
    char stringB[100010];
    while(scanf("%s %s", stringA, stringB) == 2){
        int match = 1;
        int i = 0, j = 0;
        for(; i < strlen(stringA); i++){
            for(; j < strlen(stringB); j++){
                if(stringA[i] == stringB[j]){
                    j++;
                    if(i == strlen(stringA) - 1){
                        j+= strlen(stringB);
                    }
                    break;
                }
            }
            if(i < strlen(stringA) && j== strlen(stringB)){
                match = 0;
            }
        }
        if(match){
            printf("Yes\n");
        }else{
            printf("No\n");
        }

    }
    return 0;
}
