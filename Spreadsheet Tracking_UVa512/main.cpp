#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define max_1 20
#define max_2 100
#define max_3 100


using namespace std;

int opes[max_1][max_2];
int trackP[max_3][4];

void readOperation();
int readPoints();
int operation(char* opes);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int x, y, counter = 1;
    while(scanf("%d%d%d", &x, &y) == 2){
        printf("Spreadsheet #%d\n",counter);
        counter ++;
        readOperation();
        readPoints();
        for(int i = 0; i < max_1; i++ ){
            int Operation = opes[i][0];
            if(Operation == -1) break;
            switch (Operation){
            case 'E' + 'X': {
                for(int j = 0; trackP[j][0] != -1; j++){
                    if(trackP[j][2] == opes[i][1] && trackP[j][3] == opes[i][2]) {trackP[j][2] = opes[i][3]; trackP[j][3] = opes[i][4]; continue;}
                    if(trackP[j][2] == opes[i][3] && trackP[j][3] == opes[i][4]) {trackP[j][2] = opes[i][1]; trackP[j][3] = opes[i][2]; continue;}
                }
                break;
            }
            case ('D' + 'R'):
                for(int j = 0; trackP[j][0] != -1; j++)
                    if(opes[i][trackP[j][2]] > opes[i][trackP[j][2] - 1] || (trackP[j][2] == 1 && opes[i][trackP[j][2]] > 0))
                        trackP[j][2] = trackP[j][3] = 0;
                    else trackP[j][2] -= opes[i][trackP[j][2]];
            case ('D' + 'C'):
                for(int j = 0; trackP[j][0] != -1; j++)
                    if(opes[i][trackP[j][3]] > opes[i][trackP[j][3] - 1] || (trackP[j][3] == 1 && opes[i][trackP[j][3]] > 0))
                        trackP[j][2] = trackP[j][3] = 0;
                    else trackP[j][3] -= opes[i][trackP[j][3]];
            case ('I' + 'R'):
                for(int j = 0; trackP[j][0] != -1; j++)
                    trackP[j][2] += opes[i][trackP[j][2]];
            case ('I' + 'C'):
                for(int j = 0; trackP[j][0] != -1; j++)
                    trackP[j][3] += opes[i][trackP[j][3]];
            }
        }
        for(int j = 0; trackP[j][0] != -1; j++){
            printf("Cell data in (%d,%d)", trackP[j][0], trackP[j][1]);
            if(trackP[j][2] == 0) printf("GONE");
            else printf("moved to (%d,%d)", trackP[j][2], trackP[j][3]);
        }
    }
    return 0;
}

void readOperation()
{
    int nums;
    scanf("%d", &nums);
    memset(opes, 0, max_1 * max_2);
    char ops[max_2];
    char c;
    for(int i = 0; i < nums; i++){
        scanf("%s", ops);
        opes[i][0] = operation(ops);
        for(int j = 1; j < max_2; j++){
            c = getchar();
            if(c == ' '){
                j --;
                continue;
            }
            if(c == '\n' || c == '\r'){
                break;
            }
            if(ops[0] == 'E') ops[i][j] = c - '0';
            else ops[i][c - '0'] = 1;
        }
        if(ops[0] != 'E'){
            for(int j = 2; j < max_2; j++){
                opes[i][j] += opes[i][j - 1];
            }
        }
    }
}

int readPoints()
{
    int num;
    scanf("%d", &num);
    int x, y;
    memset(trackP, -1, max_3 * 2);
    for(int i = 0; i < num; i++){
        scanf("%d%d", &x, &y);
        if(x == 0 && y == 0) break;
        trackP[i][0] = trackP[i][2] = x;
        trackP[i][1] = trackP[i][3] = y;
    }
}

int operation(char* opes)
{
    return opes[0] + opes[1];
}
