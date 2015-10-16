#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#define max 100

using namespace std;

char word[max];
char input[max];

char* removeRedundent(char* String);

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int round;
    while(scanf("%d%s%s", &round, word, input) == 3 && round != -1){
        char* newInput = removeRedundent(input);
        char* newWord = removeRedundent(word);
        //printf("cleaned strings:\n%s\n%s\n", newWord, newInput);
        int life = 7, i = 0, j = 0, left = strlen(newWord);
        while(i < strlen(newInput) && left > 0){
            while(true){
                if(newInput[i] == newWord[j]){
                    left --;
                    break;
                }else
                if(newWord[j] == '\0'){
                    life --;
                    break;
                }
                j++;
            }
            j = 0;
            i++;
        }
        printf("%s %d\n", "Round", round);
        //cout << "life = " << life << endl;
        if(life <= 0){
            printf("%s\n", "You lose.");
        }else if(left != 0){
            printf("%s\n", "You chickened out.");
        }else {
            printf("%s\n", "You win.");
        }
    }
    return 0;
}

char* removeRedundent(char* String)
{
    int i = 0, j = 0;
    int counter[26];
    for(int t = 0; t < 26; t++){
        counter[t] = 0;
    }
    char* newString = new char[max];
    while(i < max && String[i] != '\0'){
        if(counter[String[i] - 'a'] == 0){
            newString[j] = String[i];
            j++;
            counter[String[i] - 'a'] ++;
        }
        i++;
    }
    newString[j] = '\0';
    return newString;
}
