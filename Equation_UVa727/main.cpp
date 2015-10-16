#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int operations[6];
    operations['*' - '*'] = 2;
    operations['/' - '*'] = 2;
    operations['+' - '*'] = 1;
    operations['-' - '*'] = 1;
    char input[];
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    bool first = true;
    int cases;
    scanf("%d", &cases);
    for(int s = 0; s < cases; s++){
        if(first) first = false; else printf("\n");
        bool terminate = false;
        int start = 0;
        while(true)
    }
    return 0;
}
