//main function.

#include "problem1.h"
#include "problem2.h"
#include "problem3question.h"
#include "problem3answer.h"

int main() {

	//function calls from the other problem files! you should not need to modify this
	problem1 a;
	problem2 b;
	problem3question c;
	problem3answer d;
	a.printQuestion1();
	a.printAnswer1();
	b.printQuestion2();
	b.printAnswer2();
	c.printQuestion3();
	d.printAnswer3();
	return 0;
}
