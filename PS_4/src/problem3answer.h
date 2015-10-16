#include <iostream>
#include "problem3help.h"

class problem3answer {
public:
	void printAnswer3();
};


void problem3answer::printAnswer3() {
	problem3help a;
	std::cout << a.printAnswer() << std::endl;
}