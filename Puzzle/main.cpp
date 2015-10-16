#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

void printPuzzle(char* configuration)
{
    int i = 0;
    for(; i < 5; i++){
        cout << *(configuration + i * 5 + 0);
        for(int j = 1; j < 5; j++){
            cout << " " << *(configuration + i * 5 + j);
        }
        cout << endl;
    }
}

int main()
{
    int first = 1;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char* puzzle = new char[25];
    char operas[2000];
    int k = 1;
    while(1){
        int x = 0;
        int y = 0;
        char c;
        string line;
        int i = 0;
        for(; i < 25; i++){
            if(i % 5 == 0){
                getline(cin, line);
            }
            c = line[i % 5];
            if(c == 'Z'){
                break;
            }
            if(!isalpha(c)&&c != ' '){
                i--;
                continue;
            }
            if(c == ' '){
                x = i % 5;
                y = i / 5;
            }
            puzzle[i] = c;
        }
        if( i != 25){
            break;
        }
        i = 0;
        char d;
        while(1){
            getline(cin, line);
            int p = 0;
            for(; p < line.length(); p++){
                d = line[p];
                if(d == '0'){
                    break;
                }
                if(isalpha(d)){
                    operas[i] = d;
                    i++;
                }
            }
            if(p != line.length()){
                break;
            }
        }
        operas[i] = '0';
        if(!first){
            cout << endl;
        }
        printf("Puzzle #%d:\n", k);
        k++;
        i = 0;
        int toX = x;
        int toY = y;
        for(; operas[i] != '0'; i++){
            if(operas[i] == 'A'){
                toY = y - 1;
            }else if(operas[i] == 'B'){
                toY = y + 1;
            }else if(operas[i] == 'R'){
                toX = x + 1;
            }else if(operas[i] == 'L'){
                toX = x - 1;
            }else {
                printf("This puzzle has no final configuration.\n");
                break;
            }
            if(toX < 0 || toY < 0 || toX > 4 || toY > 4){
                printf("This puzzle has no final configuration.\n");
                break;
            }
            *(puzzle + y * 5 + x) = *(puzzle + toY * 5 + toX);
            *(puzzle + toY * 5 + toX) = ' ';
            x = toX;
            y = toY;
        }
        if(operas[i] == '0'){
            printPuzzle(puzzle);
        }
        first = 0;
    }
    return 0;
}
