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


#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

#include <cstdlib>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Queue {

protected:
	struct QueueNode {
		int number;
		QueueNode * next;
		QueueNode * prev;
		QueueNode(int num1, QueueNode * next1, QueueNode * prev1) {
			number = num1;
			next = next1;
			prev = prev1;

		}
	};
	QueueNode * front;
	QueueNode * back;

public:
	Queue();
	~Queue();
	void addBack(int);
	int getFront();
	int removeFront();
};


#endif

