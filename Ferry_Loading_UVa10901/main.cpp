#include <iostream>
#include <stdio.h>

using namespace std;

int ferrystate, mclock, n, t, m, cases, temp, s;
int carside[10000]; int cartime[10000]; int arrtime[10000];
bool first = true;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &cases);
    for(int d = 0; d < cases; d++){
        if(first) first = false; else printf("\n\n");
        scanf("%d%d%d", &n, &t, &m);
        ferrystate = mclock = 0; //ferry state: 0 left, 1 right
        char side[5];
        for(int i = 0; i < m; i++) {arrtime[i] = 0;}
        arrtime[m] = -1;
        for(int i = 0; i < m; i++){
            scanf("%d%s", &temp, side);
            if(side[0] == 'l'){carside[i] = 0; cartime[i] = temp;
            continue;}
            if(side[0] == 'r'){carside[i] = 1; cartime[i] = temp;
            continue;}
        }
        int i = 0, j, carriedNum;
        while(i < m){
            j = i;
            carriedNum = 0;
            while(carriedNum <= n && cartime[j] <= mclock && j < m){
                if(carside[j] == ferrystate){
                    carriedNum ++;
                    arrtime[j] = mclock + t;
                }
                j++;
            }
            if(carriedNum == 0){
                if(cartime[i] > mclock){
                    mclock = cartime[i];
                }
                if(carside[i] != ferrystate){
                    mclock += t;
                    ferrystate = (ferrystate + 1) % 2;
                }
                continue;
            }
            //carrying
            mclock += t;
            ferrystate = (ferrystate + 1) % 2;
            for(; arrtime[i] != 0; i++);
        }
        for(s = 0; s < m - 1; s++){
            printf("%d\n", arrtime[s]);
        }
        printf("%d", arrtime[s]);
    }
    return 0;
}
