#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int sideLength(int x1, int y1, int x2, int y2)
{
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int side, total, k = 0, in, largestArea = 0;
    scanf("%d", &side);
    total = side * side;
    int cows[100000];
    vector<int> Cowx;
    vector<int> Cowy;
    memset(cows, 0, total);
    char c;
    for(int i = side - 1; i >= 0; i--){
    	getchar();
        for(int j = 0; j < side; j++){
            c = getchar();
            in = i * side + j;
            switch (c)
            {
                case 'J': {Cowx.push_back(j); Cowy.push_back(i); cows[in] = 1; k++; break;}
                case 'B': {cows[in] = 3; break;}
                default : break;
            }
        }
    }
    int x1, y1, x2, y2, x3, y3, x4, y4, sum;
    //int x3, y3, x4, y4, sum;
    int area;
    for(int i = 0; i < k; i++){
        x1 = Cowx[i];
        y1 = Cowy[i];
        for(int j = i + 1; j < k; j++){
            x2 = Cowx[j];
            y2 = Cowy[j];
            if(abs(x2 - x1) % 2 == abs(y2 - y1) % 2){
            //if(abs(x2 - x1) % 2 == abs(y2 - y1) % 2){
                x3 = (x1 + x2 - (y1 - y2))/ 2;
                x4 = (x1 + x2 + (y1 - y2)) / 2;
                y3 = (y1 + y2 + (x1 - x2)) / 2;
                y4 = (y1 + y2 - (x1 - x2)) / 2;
                if(x3 >= 0 && x3 <side && y3 >= 0 && y3 <= side &&
                   x4 >= 0 && x4 <side && y4 >= 0 && y4 <= side){
                    sum = cows[y3 * side + x3] + cows[y4 * side + x4];
                    if(sum > 0 && sum < 3){
                        area = sideLength(x1, y1, x3, y3);
                        largestArea = area > largestArea ? area : largestArea;
                    }
                }
            }
        }
    }
    cout << largestArea;
    return 0;
}
