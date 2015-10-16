#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

int atcg[4];    //ACGT

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, r, c, error;
    scanf("%d", &n);
    for(int z = 0; z < n; z++){
        error = 0;
        scanf("%d%d", &r, &c);
        char dnas[r][c];
        for(int i = 0; i < r; i++){
            scanf("%s", &dnas[i][0]);
        }
        for(int j = 0; j < c; j++){
            atcg[0] = atcg[1] = atcg[2] = atcg[3] = 0;
            for(int i = 0; i < r; i++){
                switch (dnas[i][j]){
                case 'A': {atcg[0]++; break;}
                case 'C': {atcg[1]++; break;}
                case 'G': {atcg[2]++; break;}
                case 'T': {atcg[3]++; break;}
                default: break;
                }
            }
            if(atcg[0] == atcg[1] && atcg[1] == atcg[2] && atcg[2] == atcg[3]){
                cout << "A";
                error += (r - atcg[0]);
            }else{
                int temp = 0;
                for(int t = 1; t < 4; t++){
                    if(atcg[t] > atcg[temp]){
                        temp = t;
                    }
                }
                error += (r - atcg[temp]);
                switch(temp){
                case 0: {cout << "A"; break;}
                case 1: {cout << "C"; break;}
                case 2: {cout << "G"; break;}
                case 3: {cout << "T"; break;}
                default: break;
                }
            }
        }
        printf("\n%d\n", error);
    }
    return 0;
}
