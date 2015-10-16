#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string line;
    while(1){
        double decimal;
        int exp;
        getline(cin, line);
        stringstream ss(line);
        ss >> decimal;
        cout << decimal << endl << exp << endl;
        int E = log(log(decimal) / log(2)) / log(2) + 0.5;
        cout << E << endl;
    }
    return 0;
}
