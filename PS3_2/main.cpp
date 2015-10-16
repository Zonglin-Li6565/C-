#include <iostream>
#include <string>

using namespace std;


/*
*
*  ____ ____    _  ___   __
* / ___/ ___|  / |/ _ \ / /_
*| |   \___ \  | | (_) | '_ \
*| |___ ___) | | |\__, | (_) |
* \____|____/  |_|  /_/ \___/
*
*
*
* There is an issue in this code
* Identify the reasons why the code below is printing the wrong output
* Devise an addition to the existing code to fix the problem
* (no deleting any of the current code!)
* Correct Output: "This is the correct output!"
* DO NOT SIMPLY ASSIGN ADDRESS1 AND ADDRESS2 TO THE CORRECT VALUES
* you want to make setString do what it is intended to do.
* reference http://www.cplusplus.com/doc/tutorial/pointers/ for additional information on pointers!
*/

//YOU CAN ONLY CHANGE THIS FUNCTION
void setString(string address2, string address3) {
	address2 = address3;
	return;
}











int main() {
	//variable declarations
	string address1("This is the ");
	string address2("incorrect output :(");
	string address3("correct output!");
	string *pointer1 = &address1;
	string *pointer2 = &address2;
	string *pointer3 = &address3;
	setString(address2, address3); //See line 23
	cout << address1 + address2 << endl;

	return 0;
}
