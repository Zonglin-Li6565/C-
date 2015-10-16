#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <math.h>

using namespace std;

char readChar()
{
    char c = getchar();
    while(c == '\n' || c == '\r'|| c == ' '){
        c = getchar();
    }
    return c;
}

int readInt(int digits)
{
    int value = 0;
    char c;
    for(int i = digits - 1; i >= 0; i--){
        c = readChar();
        value += (1 << i) * (c - '0');
    }
    return value;
}

int main()
{
    int digits;
    while(scanf("%d", &digits) == 1){
        cout << digits << endl;
        printf("=%d\n", readInt(digits));
    }
    return 0;
}
