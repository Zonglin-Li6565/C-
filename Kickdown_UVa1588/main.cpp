#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

char up[100];
char below[100];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int i, j, found, length, temp;
    while(scanf("%s%s", up, below) == 2){
        //printf("%s\n%s\n", up, below);
        found = 1;
        length = 0;
            for(i = 0; i < strlen(up); i++){
                found = 1;
                j = i;
                for(; (j < strlen(up)) && ((j - i) < strlen(below)); j++){
                    if((up[j] + below[j - i] - 2 * '0') > 3){
                        //printf("j = %d; j - i = %d", j, j - i);
                        found = 0;
                        break;
                    }
                }
                //cout << "found = " << found << endl;
                if(found){
                    length = (i + strlen(below) <= strlen(up)) ? strlen(up) : i + strlen(below);
                    break;
                }
            }
            if(!found){
                length = strlen(below) + strlen(up);
            }
            for(i = 0; i < strlen(below); i++){
                found = 1;
                j = i;
                for(; (j < strlen(below) && (j - i) < strlen(up)); j++){
                    if((below[j] + up[j - i] - 2 * '0') > 3){
                        found = 0;
                        break;
                    }
                }
                if(found){
                    temp = (i + strlen(up) <= strlen(below)) ? strlen(below) : i + strlen(up);
                    //cout << "temp = " << temp << "; length = " << length << endl;
                    if(temp < length){
                        length = temp;
                    }
                    break;
                }
            }
            if(!found){
                printf("%d\n", strlen(below) + strlen(up));
            }else{
                printf("%d\n", length);
            }
    }
    return 0;
}
