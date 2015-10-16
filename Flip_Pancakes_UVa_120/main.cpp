#include <iostream>
#include <stdio.h>

using namespace std;

int pancakes[40];
int track[101];
int length, largestIndex;

void solve (int trackIndex, int length);

int main()
{
    bool terminate = false;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while(!terminate){
        length = 0;
        largestIndex = 0;
        for(int j = 0;j < 101; j++) track[j] = -1;
        while(true){
            char c = getchar();
            if(c == ' ') continue;
            if(c == '\n' || c == '\r') break;
            if(c == EOF) {terminate = true; break;}
            int radii = c - '0';
            pancakes[length] = radii;
            length++;
        }
        int i = 0;
        for(; i < length - 1; i++){
            cout << pancakes[i] << " ";
        }
        cout << pancakes[i] << endl;
        for(int i = length; i >= 1; i--){
            int radii = pancakes[length - i];
            //printf("radii = %d\n", radii);
            track[radii] = i;
            if(radii > largestIndex) largestIndex = radii;
        }
        solve(largestIndex, length);
    }
    return 0;
}

void flip(int endIndex)
{
    cout << endIndex << " ";
    endIndex = length - endIndex;
    //printf("endIndex = %d\n", endIndex);
    for(int i = 0; i < endIndex / 2 + 1; i++){
        int temp = pancakes[i];
        pancakes[i] = pancakes[endIndex - i];
        pancakes[endIndex - i] = temp;
        //printf("swanp %d, with %d\n", pancakes[i], pancakes[endIndex - i]);
    }
}

void solve (int trackIndex, int leng)
{
    if(leng == 1){
        cout << "0" << endl;
        return;
    }
    int spot = length - leng + 1;
    int location = track[trackIndex];
    if(location != spot){
        if(location != length)
            flip(location);
        flip(spot);
        for(int i = 0; i < leng; i++){
            track[pancakes[i]] = length - i;
            //printf("for radii = %d, location = %d\n", pancakes[i], length - i);
        }
    }
    int j = trackIndex - 1;
    for(; j > 0; j--){
        if(track[j] != -1){
            solve(j, leng - 1);
            break;
        }
    }
}
