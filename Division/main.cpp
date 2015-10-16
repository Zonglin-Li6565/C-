#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, whole, remainder, i, start, marker, cycleSize, matching, doubleChecking, counter, checked;
    while(scanf("%d %d", &a, &b) == 2){
        int cache_i = 0;
        int cache_remainder = 0;
        int checkDigit = 0;
        checked = 0;
        counter = 0;
        doubleChecking = 0;
        vector<int> entries;
        vector<char> decimal;
        whole = a / b;
        remainder = a % b;
        i = 0;
        cycleSize = 0;
        start = 1;
        marker = 0;
        matching = 0;
        remainder *= 10;
        decimal.push_back(remainder / b + 48);
        remainder = remainder % b;
        i++;
        while(1){
            int retry = 0;
            remainder *= 10;
            if(i < decimal.size()){
                decimal[i] =  (remainder / b + 48);
            }else{
                decimal.push_back(remainder / b + 48);
            }
            if(!matching){
                for(int j = i - 1; j > -1; j --){
                    if(decimal[j] == decimal[i]){
                        entries.push_back(j);
                    }
                }
                if(!entries.size() == 0){
                    cache_i = i + 1;
                    cache_remainder = remainder % b;
                    start = i;
                    matching = 1;
                }
            }
            if(matching){
                for(int j = entries.size() - 1; j > -1 ; j--){
                    if(((decimal[i] != decimal[entries[j] + i - start]) && !doubleChecking ||
                       ((decimal[i] != checkDigit) && doubleChecking))){
                        int temp = entries[j];
                        entries[j] = entries[entries.size() - 1];
                        entries[entries.size() - 1] = temp;
                        entries.pop_back();
                        if(entries.size() == 0){
                            i = cache_i;
                            remainder = cache_remainder;
                            retry = 1;
                            doubleChecking = 0;
                            counter = 0;
                            matching = 0;
                            break;
                        }
                        continue;
                    }
                    if(doubleChecking){
                        if(counter < 6){
                            counter ++;
                            break;
                        }else{
                            checked = 1;
                            break;
                        }
                    }
                    if(entries[j] + i - start == start){
                        marker = entries[j];
                        cycleSize = start - marker;
                        if(cycleSize < 2){
                            doubleChecking = 1;
                            checkDigit = decimal[start];
                            counter = 0;
                        }else{
                            break;
                        }
                    }
                }
            }
            if(retry){
                continue;
            }
            if(cycleSize > 1 || checked){
                break;
            }
            i++;
            remainder = remainder % b;
        }
        printf("%d/%d = %d.", a, b, whole);
        char repeating[cycleSize > 50? 53: cycleSize];
        int sizeofNonRep = start - cycleSize;
        char nonRepeating[sizeofNonRep];
        for(int q = 0; q < sizeofNonRep; q++){
            nonRepeating[q] = decimal[q];
            cout << decimal[q] - 48;
        }
        cout << "(";
        int q = 0;
        for(; q < (cycleSize > 50? 50: cycleSize); q++){
            repeating[q] = decimal[start + q];
            cout << decimal[start + q] - 48;
        }
        if(cycleSize > 50){
            cout << "...";
        }
        cout << ")";
        if(cycleSize > 50){
            repeating[52] = repeating[51] = repeating[50] = 46;
        }
        printf("\n   %d = number of digits in repeating cycle\n\n", cycleSize);
    }
    return 0;
}
