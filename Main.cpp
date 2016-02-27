/******************************************************************************************
** Program Filename: Lab 9
** Author: Megan Aldridge
** Date: February 28, 2016
** Description: This program allows a user to store integers, display, and remove integers
**		from a doubly-linked circular queue. 
** Input: User will select from a menu to determine if an integer is added, displayed,	
**		and/or removed from the queue. 
** Output: There is a menu that is output to the user as well as basic cout statements
**		indicating the results.
******************************************************************************************/


#include "CircularQueue.hpp"
#include <string>
#include <sstream>
using std::string;


/******************************************************************************************
** Function: Menu
** Description: This functions displays a menu to the user, allows them to input a string
**		depending on their choice. Then, the non-numeric element of the string is parsed off
**		and remaining string is tested to determine all elements are integers (for selection
**		a) ). For any other selection, the string value is assigned a negative integer 
**		(depending on user's selection). The string containing numeric values (positive or
**		negative) is converted to an integer and returned from the menu. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: The user's menu selection string is converted into an integer and returned
**		by the function. 
******************************************************************************************/
int menu() {

	string num;
	string input;
	bool flag = false;

	do {
		cout << "Circular Queue Menu" << endl;
		cout << "Please enter \"letter)\" or for a: \"a) integer\" " << endl;
		cout << "Include a space after the parenthesis." << endl;
		cout << "a) Enter a value" << endl;
		cout << "b) Display first value" << endl;
		cout << "c) Remove a value" << endl;
		cout << "d) Display the queue contents" << endl;
		cout << "x) Exit" << endl;
		cout << "Choice: ";
		std::getline(cin, num);

		string parseVal = " ";
		input = num.substr(0, num.find(parseVal));
		num.erase(0, num.find(parseVal) + 1);

		if (input == "a)") {
			cout << "You chose a)" << endl;
			flag = true;
			for (int i = 0; i < num.length(); i++) {
				if (isdigit(num[i])) {
				}
				else {
					cout << "Please follow \"a)\" with an integer "<< endl;
					flag = false;
				}
			}
			
		}
		else if (input == "b)") {
			//cout << "You chose b)" << endl;
			flag = true;
			num = "-2";
		}
		else if (input == "c)") {
			//cout << "You chose c)" << endl;
			flag = true;
			num = "-3";
		}
		else if (input == "d)") {
			//cout << "You chose d)" << endl;
			flag = true;
			num = "-4";
		}
		else if (input == "x)") {
			//cout << "You chose x)" << endl;
			flag = true;
			num = "-5";
		}
		else {
			//cout << "Went here" << endl;
		}
	} while (flag == false);

	int value;
	std::istringstream(num) >> value;



	cout << "Num is: " << num << endl;
	cout << "Input is: " << input << endl;
	return value;
}



/******************************************************************************************
** Function: Menu
** Description: Main will call CircularQueue functions for display, add, or remove integers
**		and display results until the user chooses to exit. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
int main() {
	int s1;
	Queue q1;

	do {
		s1 = menu();

		if (s1 == -2) {
			if (q1.getFront() == -1) {
				cout << "First Value: N/A (The queue is empty) " << endl;
			}
			else {
				cout << "First Value: " << q1.getFront() << endl;
			}
		}

		else if (s1 == -3) {
			int removeStatus = q1.removeFront();
			if (removeStatus == -1) {
				cout << "Removal of value unsuccessful. " << endl;
				cout << "\n Nothing to remove." << endl;
			}
		}

		else if (s1 == -4) {
			do {
				cout << q1.removeFront() << " ";
			} while (!(q1.getFront() == -1));
			cout << endl;
		}

		else if ( s1 > 0) {
			cout << s1 << " successfully added." << endl;
			q1.addBack(s1);
		}

		else {

		}
	} while (!(s1 == -5));

	cout << "Goodbye" << endl;

	return 0;
}
