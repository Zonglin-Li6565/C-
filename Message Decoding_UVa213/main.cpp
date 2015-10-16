#include <stdio.h>
#include <string.h>
#define Length 8

using namespace std;

bool first = true;

char code[Length][1<<Length];

bool clean();

int readHeader();

int readInt(int digits);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(readHeader()){
        int length, terminate, read = 0;
        do{
            length = readInt(3);
            terminate = (1 << length) - 1;
            for(read = readInt(length); read != terminate; read = readInt(length))
                if(code[length][read] == -1) continue; else putchar(code[length][read]);
        }while(length > 0);
        if(clean()) break;
        putchar('\n');
    }
    return 0;
}

int readHeader()
{
    memset(code, -1, Length * (1<<Length));
    int terminate;
    char c;
    for(int i = 0; i < Length; i++){
        terminate = (1 << i) - 1;
        for(int j = 0; j < terminate; j++){
            c = getchar();
            if(i >= 0 && (c == '\n' || c == '\r')){
                return 1;
            }
            if(c == EOF){
                return 0;
            }
            code[i][j] = c;
        }
    }
    return 1;
}

int readInt(int digits)
{
    int value = 0;
    char c;
    for(int i = digits - 1; i >= 0; i--){
        c = getchar();
        if(c == '\n' || c == '\r'){i++; continue;}
        value += (1 << i) * (c - '0');
    }
    return value;
}

bool clean()
{
    char c;
    bool finish = false;
    while(true){
        c = getchar();
        if(c == EOF) {finish = true; break;}
        if(c == '\n' || c == '\r'){
            break;
        }
    }
    return finish;
}
