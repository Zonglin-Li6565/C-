#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    int answers[n];
    for(int t = 0; t < n; t++){
        int score = 0;
        char String[90];
        scanf("%s", String);
        int length = strlen(String);
        for(int i = 0; i < length; i ++){
            if(String[i] == 'O'){
                int consecutive = 0;
                while(String[i] == 'O' && i < length){
                    i ++;
                    consecutive ++;
                    score += consecutive;
                }
            }
        }
        answers[t] = score;
    }
    for(int i = 0; i < n; i++){
        cout << answers[i] << endl;
    }
    return 0;
}
