/*
************************************************
  ____ ____    _  ___   __
 / ___/ ___|  / |/ _ \ / /_
| |   \___ \  | | (_) | '_ \
| |___ ___) | | |\__, | (_) |
 \____|____/  |_|  /_/ \___/
Problem Set 2
Problem 1
There are numerous syntactical errors in the code below
If the code successfully compiles, you are done with this problem!
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
************************************************
*/

#include <iostream>

using namespace std;

void printSecondary() {
    cout << "... but maybe I will make a better one one day?" << endl;
}

int main() {
    for (int i = 0; i < 10; i++){
        cout << "I wish I had " << i << " startups." << endl;

        if (i == 3) {
            cout << "I hate my startup." << endl;
            printSecondary();
        }
    }
}
