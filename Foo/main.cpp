#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    int inputsize;
    int previous;
    scanf("%d%d", &inputsize, &previous);
    for(int i = 0; i < inputsize - 1; i++){
        int current;
        scanf("%d", &current);
        if(current - previous != 2){
            cout << (previous + 2);
            break;
        }
        previous = current;
    }
    return 0;
}

void findingDigits(vector < int > foo) {
    int counter;
    for(int i = 0; i < foo.size(); i++){
        counter = 0;
        int value = foo[i];
        int temp = value;
        while(temp > 0){
            int temp_2 = temp % 10;
            temp /= 10;
            if(temp_2 != 0 && temp_2 * (value / temp_2) == value) counter ++;
        }
        cout << counter << endl;
    }
}
