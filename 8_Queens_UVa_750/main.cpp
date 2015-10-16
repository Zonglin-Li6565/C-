#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int answer[8];
int cases, counter, x, y;
bool first = true;
vector<string> results;

void solve(int row);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d",&cases);
    for(int z = 0; z < cases; z++){
        if(first) first = false; else printf("\n");
        for(int i = 0; i < 8;i ++){ answer[i] = -1; }
        counter = 1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        scanf("%d%d", &x, &y);
        answer[y - 1] = x - 1;
        solve(0);
        sort(results.begin(), results.end());
        int i = 0;
        for(; i < results.size() - 1; i++){
            if(i + 1 < 10)
                cout << " " << (i + 1) << "      " << results[i] << endl;
            else
                cout << (i + 1) << "      " << results[i] << endl;
        }
        if(i + 1 < 10)
            cout << " " << (i + 1) << "      " << results[i] << endl;
        else
            cout << (i + 1) << "      " << results[i] << endl;
        results.clear();
    }
    return 0;
}

void solve(int row)
{
    if(answer[row] != -1){
        if(row < 7){
            solve(row + 1);
        }else{
            string s;
            int t = 0;
            for(; t < 7; t++){
                s += (answer[t] + 1) + '0';
                s += ' ';
            }
            s += (answer[t] + 1) + '0';
            results.push_back(s);
        }
        return;
    }
    for(int i = 0; i < 8; i++){
        bool conflict = false;
        for(int j = 0; j < 8; j++){
            if(answer[j] != -1 && j != row){
                if(answer[j] == i || abs(answer[j] - i) == abs(j - row)){
                    conflict = true;
                    break;
                }
            }
        }
        if(conflict) continue;
        answer[row] = i;
        if(row < 7){
            solve(row + 1);
        }else{
            string s;
            int t = 0;
            for(; t < 7; t++){
                s += (answer[t] + 1) + '0';
                s += " ";
            }
            s += (answer[t] + 1) + '0';
            results.push_back(s);
        }
        answer[row] = -1;
    }
    return;
}
