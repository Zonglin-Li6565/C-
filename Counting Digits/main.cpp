#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{

    int n, temp;
    scanf("%d", &n);
    int toHandle[n];
    int counter[10];
    for(int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        toHandle[i] = k;
    }
    for(int t = 0; t < n; t++){
        int m = toHandle[t];
        for(int i = 0; i < 10; i++){
            counter[i] = 0;
        }
        for(int i = 1; i <= m; i ++){
            temp = i;
            while(temp > 0){
                counter[temp % 10] ++;
                temp /= 10;
            }
        }
        cout << counter[0];
        for(int i = 1; i < 10; i++){
            cout << " " << counter[i];
        }
        cout << endl;
    }
    return 0;
}
