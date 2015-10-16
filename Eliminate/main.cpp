#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n, m, counter, index;
    scanf("%d%d", &n, &m);
    int* children = new int[n];
    for(int i = 0; i < n; i++){
        children[i] = 1;
    }
    index = -1;
    counter = n;
    while(counter >= m){
        int i = 0;
        for(; i != m; ){
            index ++;
            if(children[index % n] != -1){
                i++;
            }
        }
        //cout << "remove :" << index % n + 1 << endl;
        children[index % n] = -1;
        counter --;
        //cout << "counter = " << counter << endl;
    }
    for(int i = 0; i < n; i++){
        if(children[i] > 0){
            printf("%d\n", i + 1);
        }
    }
    return 0;
}
