#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int solve (int* food, int* Count, int x, int y)
{
    int max_1 = 0, max_2 = 0, max_3 = 0, max_4 = 0;
    bool next = false;
    if(food[x - 1][y] > 0){
        max_1 = solve(food, Count, x - 1, y);
        food[x - 1][y] += 1;
        next = true;
    }
    if(food[x + 1][y] > 0){
        max_2 = solve(food, Count, x + 1, y);
        food[x + 1][y] += 1;
        next = true;
    }
    if(food[x][y - 1] > 0){
        max_1 = solve(food, Count, x, y - 1);
        food[x][y - 1] += 1;
        next = true;
    }
    if(food[x][y + 1] > 0){
        max_1 = solve(food, Count, x, y + 1);
        food[x][y + 1] += 1;
        next = true;
    }
    food[x][y] --;
    if(!next){
        Count[x][y]++;
        return 1;
    }
    max_1 = max_1 > max_3 ? max_1 : max_3;
    max_2 = max_2 > max_4 ? max_2 : max_4;
    return 1 + (max_1 > max_2 ? max_1 : max_2);
}
