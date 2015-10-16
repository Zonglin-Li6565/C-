#include <stdio.h>
#include <iostream>

using namespace std;

int is3Multiple(int x);

int is5Multiple(int x);

int is7Multiple(int x);


int main()
{
    cout << "started" << endl;
    freopen("input.in", "r", stdin);
    freopen("Output.out", "w" ,stdout);
    int i = 1;
    int a = 0;
    int b = 0;
    int c = 0;
    int number = -1;
    while(scanf("%d %d %d", &a, &b, &c) == 3){
        if(a > 3 || b > 5 || c > 7){
            break;
        }
        number = -1;
        for(int j = 10; j < 101; j++){
            if(is3Multiple(j - a) && is5Multiple(j - b) && is7Multiple(j - c)){
                number = j;
                break;
            }
        }
        if(number == -1){
            printf("case %d: No answer\n", i);
        }else{
            //cout << "case " << i << ": " << number << endl;
            printf("case %d: %d\n", i, number);
        }
        a = 0;
        b = 0;
        c = 0;
        i ++;
    }
    return 0;
}

int is3Multiple(int x)
{
    if(x / 3 * 3 == x){
        return 1;
    }
    return 0;
}

int is5Multiple(int x)
{
    if(x / 5 * 5 == x){
        return 1;
    }
    return 0;
}

int is7Multiple(int x)
{
    if(x / 7 * 7 == x){
        return 1;
    }
    return 0;
}
