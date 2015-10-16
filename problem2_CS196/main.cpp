/*
************************************************
  ____ ____    _  ___   __
 / ___/ ___|  / |/ _ \ / /_
| |   \___ \  | | (_) | '_ \
| |___ ___) | | |\__, | (_) |
 \____|____/  |_|  /_/ \___/
Problem Set 2
Problem 2
This program is missing something that lets you use the pow() function.
If the program successfully compiles, you have finished this problem!
We suggest you start by compiling and looking at the errors
Compilation instructions:
C++ is usually compiled with one of 3 programs
On Mac or Linux:
    try one of 2 commands in the directory of this problem
    1. g++ problem1.cpp
    2. clang++ problem1.cpp
    if neither works:
    On Mac make sure you install xcode (Mac App Store)
    and install the developer tools
    On linux run [your package manager] install clang
    i.e sudo apt-get install clang
On Windows:
    download visual studio express and open this file in that
    and hit the play button to compile
    Or even easier do the hw on ews and follow the clang command
    for linux
Hint- read this page:
http://www.cplusplus.com/reference/cmath/pow/
************************************************
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 3; j > 0; j--) {
            cout << pow(i, j) << endl;
        }
    }
}
