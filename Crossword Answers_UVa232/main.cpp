#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int r, c, n = 1, counter;
    vector<int> acrossstarts;
    vector<int> downstarts;
    char puzzle[101];
    char number[100];
    char read = ' ';
    while((scanf("%d%d", &r, &c) == 2)){
        counter = 1;
        acrossstarts.clear();
        downstarts.clear();
        if(r > 10 || c > 10){
            break;
        }
        if(n > 1){
           printf("\n");
        }
        printf("puzzle #%d:\nAcross\n", n);
        n++;
        for(int i = 0; i < r * c; ){
            read = getchar();
            if(read == '*' || isalpha(read)){
                number[i] = 0;
                puzzle[i] = read;

                if((i - 1 < 0 || puzzle[i - 1] == '*' || i % c == 0) && read != '*'){
                    acrossstarts.push_back(i);
                    number[i] = counter;
                    //printf("number[%d] = %d", i, number[i]);
                    counter ++;
                }
                if((i - c < 0 || puzzle[i - c] == '*') && read != '*'){
                    downstarts.push_back(i);
                    number[i] = number[i] == 0 ? counter++ : number[i];
                    //printf("number[%d] = %d", i, number[i]);
                }
                i++;
            }
        }
        int j, k;
        /***********************across***********************/
        j = 0;
        for(int i = 0; i < acrossstarts.size(); i++){
            j = acrossstarts[i];
            if(number[j] < 10){
                printf("  %d.", number[j]);
            }else{
                printf(" %d.", number[j]);
            }
            k = j / c * c;
            while(puzzle[j] != '*' && j - k < c){
                cout << puzzle[j];
                j++;
            }
            printf("\n");
        }
        printf("Down\n");
        /************************down************************/
        j = 0;
        for(int i = 0; i < downstarts.size(); i++){
            j = downstarts[i];
            if(number[j] < 10){
                printf("  %d.", number[j]);
            }else{
                printf(" %d.", number[j]);
            }
            while(puzzle[j] != '*' && j / c < r){
                cout << puzzle[j];
                j += c;
            }
            printf("\n");
        }
    }
    return 0;
}
