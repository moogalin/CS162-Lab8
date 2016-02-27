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

// int, next, prev
#include "CircularQueue.hpp"

Queue::Queue() {
	QueueNode *ptr = front;
	ptr= new QueueNode(-1, ptr, ptr);
	front = ptr;
	back = ptr;

	ptr = new QueueNode(-1, front, back);
	front->prev = ptr;
	front->next = ptr;


	ptr = new QueueNode(-1, back, front->next);
	back->prev = ptr;
	front->next = ptr;
}

Queue::~Queue() {

}

void Queue::addBack(int num) {

	if ((back == front) && (back->number == -1)) {
		cout << "The queue is empty" << endl;
		cout << "And we want to add: " << num << endl;
		back->number = num;
		cout << "Back contains: " << back->number << endl;
	}

	else if ((back->next)->number == -1) {
		cout << "The queue already has a value" << endl;
		cout << "We will add another" << endl;
		(back->next)->number = num;
		back = (back->next);
		cout << "Back contains: " << back->number << endl;
	}

	else if ((back->next) == front) {
		cout << "The queue is full and we must add another node" << endl;
		QueueNode * ptr = new QueueNode(num, front, back);
		(back->next) = ptr;
		(front->prev) = ptr;
		back = (back->next);
		cout << "Back now contains: " << back->number << endl;
	}

	else {
		cout << "Something is wrong" << endl;
	}


}

int Queue::getFront() {
	int frontVal;
	if ((front == back) && (front->number == -1)) {
		frontVal = -1;
	}

	else {
		frontVal = front->number;

	}
	return frontVal;

} 

int Queue::removeFront() {

	int removedInt;
	
	if ((front == back) && (front->number == -1)) {
		cout << "The queue is empty, we cannot remove a value" << endl;
		removedInt = -1;
	}

	else if (front == back) {
		removedInt = front->number;
		front->number = -1;
	}

	else if (!(front->number == -1)) {
		removedInt = front->number;
		front->number = -1;
		front = (front->next);
	}

	return removedInt;

}



/*
Queue::Queue() {

	head = NULL;
	tail = NULL;

}

Queue::~Queue() {

	if (head == NULL) {
		return;
	}

	while (head != NULL) {
		if (head == tail) {
			Node *temp = head;
			head = NULL;
			tail = NULL;
			delete temp;

		}

		else {
			Node *temp = head;
			head = head->prev;
			head->next = NULL;
			temp->prev = NULL;
			delete temp;
			temp = NULL;

		}
	}
}

void Queue::add(int num1) {

	if (head == NULL && tail == NULL) {
		Node *ptr = new Node(num1);
		tail = ptr;
		head = ptr;
		ptr = NULL;

	}

	else {
		Node * ptr = new Node(num1, tail, NULL);
		tail->prev = ptr;
		tail = ptr;
		ptr = NULL;
	}

}

int Queue::remove() {

	if (head == NULL) {
		cout << "Nothing to remove!" << endl;
		return 0;
	}

	else if (head == tail) {
		Node *temp = head;
		int removedInt = head->number;
		head = NULL;
		tail = NULL;
		delete temp;
		return removedInt;

	}

	else {
		Node *temp = head;
		int removedInt = head->number;
		head = head->prev;
		head->next = NULL;
		temp->prev = NULL;
		delete temp;
		temp = NULL;
		return removedInt;

	}

	return 0;
}

void Queue::display() {

	if (head == NULL) {
		cout << "Nothing to display!" << endl;
	}

	Node * nodePtr = tail;

	while (nodePtr != NULL) {
		cout << nodePtr->number << " ";
		nodePtr = nodePtr->next;
	}

	nodePtr = NULL;


}
*/