#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

char readChar()
{
    char c;
    c = getchar();
    while(c != EOF && !isalpha(c)){
        c = getchar();
    }
    return c;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int alphabet[26];
    char line[52];
    int End = 0;
    int largest = 0;
    char read = readChar();
    for(int i = 0; i < 26; i++){
        alphabet[i] = 0;
    }
    while(read != EOF){
        alphabet[read - 'A'] ++;
        if(alphabet[read - 'A'] > largest) largest = alphabet[read - 'A'];
        read = readChar();
    }
    for(; largest > 0; largest --){
         memset(line, 0, 26);
         for(int i = 0; i < 26; i++){
            if(alphabet[i] < largest){
                line[i * 2] = ' ';
            }else{
                line[i * 2] = '*';
                End = i * 2 + 1;
            }
            line[i * 2 + 1] = ' ';
         }
         line[End] = '\0';
         printf("%s\n", line);
    }
    for(int i = 0; i < 26; i++){
        line[i * 2] = i + 'A';
        line[i * 2 + 1] = ' ';
    }
    line[51] = '\0';
    printf("%s\n", line);
    return 0;
}
