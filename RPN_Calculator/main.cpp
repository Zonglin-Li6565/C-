#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> Number;

int main()
{
    int temp = 0, x, y;
    char c;
    while(true){
        c = getchar();
        if(c == EOF || c == '\n' || c == '\r') {if(temp != 0) Number.push_back(temp); break;}
        if(c <= '9' && '0' <= c){
            if(temp == 0)
                temp = c - '0';
            else
                temp = temp * 10 + (c - '0');
            continue;
        }
        if(c == ' '){
            if(temp != 0){
                Number.push_back(temp);
                temp = 0;
            }else{
                continue;
            }
        }
        switch(c){
        case '+': {x = Number.back(); Number.pop_back(); y = Number.back(); Number.pop_back(); Number.push_back(y + x); break;}
        case '-': {x = Number.back(); Number.pop_back(); y = Number.back(); Number.pop_back(); Number.push_back(y - x); break;}
        case '*': {x = Number.back(); Number.pop_back(); y = Number.back(); Number.pop_back(); Number.push_back(y * x); break;}
        case '/': {x = Number.back(); Number.pop_back(); y = Number.back(); Number.pop_back(); Number.push_back(y / x); break;}
        }
    }
    printf("%d", Number.back());
    return 0;
}
