#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

string results[2] = {"IMPOSSIBLE", "POSSIBLE"};

struct Board{
    bool isNull;
    int sides[2];
    void setSides(int s1, int s2){
        sides[0] = s1;
        sides[1] = s2;
    }
    void setNull(){
        isNull = true;
        setSides(-1, -1);
    }
    bool is_Null(){
        return isNull;
    }
    int getSide1(){
        return sides[0];
    }
    int getSide2(){
        return sides[1];
    }
    Board(){
        isNull = false;
        setSides(0, 0);
    }
};

int isSame(Board b1, Board b2){
    if((b1.getSide1() == b2.getSide1() && b1.getSide2() == b2.getSide2()) ||
       (b1.getSide2() == b2.getSide1() && b1.getSide1() == b2.getSide2())){
        return 1;
    }
    return 0;
}

int canJoint(Board b1, Board b2){

    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c, d, e, f, g, h, i, j, k, l;
    while(scanf("%d%d%d%d%d%d%d%d%d%d%d%d",
                &a, &b, &c, &d, &e, &f, &g, &h, &i, &j, &k, &l) == 12){
        Board boards[6];
        Board differentBoards[3];
        //printf("(%d, %d); (%d, %d); (%d, %d); (%d, %d); (%d, %d); (%d, %d); \n",
               //a, b, c, d, e, f, g, h, i, j, k, l);
        int possibility = -1;
        boards[0].setSides(a, b);
        boards[1].setSides(c, d);
        boards[2].setSides(e, f);
        boards[3].setSides(g, h);
        boards[4].setSides(i, j);
        boards[5].setSides(k, l);
        int k = 0;
        for(int i = 5; i > -1; i--){
            if(boards[i].isNull){
                continue;
            }
            int j = i - 1;
            for(; j  > -1; j--){
                if(!boards[j].is_Null() && isSame(boards[i], boards[j])){
                    differentBoards[k].setSides(boards[i].getSide1(), boards[i].getSide2());
                    k ++;
                    boards[i].setNull();
                    boards[j].setNull();
                    break;
                }
            }
            if(j == -1 && i > 0){
                possibility = 0;
                break;
            }
        }
        if(possibility == 0){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int currentSide = 0;
        int i = 0;
        for(; i < 3; i++){
            if(differentBoards[i % 3].sides[currentSide] == differentBoards[(i + 1) % 3].sides[0]){
                currentSide = 1;
                continue;
            }else
            if(differentBoards[i % 3].sides[currentSide] == differentBoards[(i + 1) % 3].sides[1]){
                currentSide = 0;
                continue;
            }else {
                break;
            }
        }
        currentSide = 1;
        int p = 0;
        for(; p < 3; p++){
            if(differentBoards[p % 3].sides[currentSide] == differentBoards[(p + 1) % 3].sides[0]){
                currentSide = 1;
                continue;
            }else
            if(differentBoards[p % 3].sides[currentSide] == differentBoards[(p + 1) % 3].sides[1]){
                currentSide = 0;
                continue;
            }else {
                break;
            }
        }
        if(i == 3 || p == 3){
            cout << "POSSIBLE" << endl;
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
