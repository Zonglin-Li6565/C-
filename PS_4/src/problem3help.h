/*
 * problem3help.h
 *
 *  Created on: Oct 15, 2015
 *      Author: zonglin
 */
#include <string>

#ifndef PROBLEM3HELP_H_
#define PROBLEM3HELP_H_

class problem3help {
	public:
		std::string printQuestion();
		std::string printAnswer();
};


std::string problem3help::printQuestion() {
	return "This is the question for problem 3";
}

std::string problem3help::printAnswer() {
	return "This is the answer for problem 3!";
}

#endif /* PROBLEM3HELP_H_ */

