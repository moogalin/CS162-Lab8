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

/******************************************************************************************
** Function: Constructor
** Description: This function creates a circularly linked Queue with three nodes who all
**		contain the sentinel, -1, data value. Both front and back pointers point to a single
**		node. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: Circularly linked Queue created with three nodes. 
******************************************************************************************/
Queue::Queue() {

	QueueNode *ptr1 = new QueueNode(-1, 0, 0);
	QueueNode *ptr2 = new QueueNode(-1, 0, 0);
	QueueNode *ptr3 = new QueueNode(-1, 0, 0);

	front = ptr1;
	back = ptr1;

	ptr1->next = ptr2;
	ptr2->prev = ptr1;

	ptr2->next = ptr3;
	ptr3->prev = ptr2;

	ptr3->next = ptr1;
	ptr1->prev = ptr3;

	
	/******* MAPPING CIRCULAR NODE ****************
	cout << "back->prev: " << back->prev << endl;
	cout << "front->prev: " << front->prev << endl;

	cout << "back: " << back << endl;
	cout << "front: " << front << endl;

	cout << "back->next: " << back->next << endl;
	cout << "front->next: " << front->next << endl;

	cout << "(back->prev)->prev" << (back->prev)->prev << endl;
	cout << "(front->prev)->prev" << (front->prev)->prev << endl;
	cout << "(back->next)->next" << (back->next)->next << endl;
	cout << "(front->next)->next" << (front->next)->next << endl;
	**********************************************/
}


/******************************************************************************************
** Function: Deconstructor
** Description: This function uses the front pointer to iterate through the Queue deleting
**		one node at a time. The pointers in the nodes flanking the to-be-deleted are 
**		redirected to each other. Effectively excluding the to-be-deleted node from the
**		circular queue. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: All allocated memory is deleted. 
******************************************************************************************/
Queue::~Queue() {

	back = NULL;
	//int count = 1;

	while (front != NULL) {
		if (front->next == front) {
			//cout << "Deconstructor deleted last node." << endl;
			QueueNode * temp = front;
			front = NULL;
			delete temp;
			temp = NULL;
		}

		else {
			//cout << "Deconstructor deleted node " << count << endl;
			//count++;
			QueueNode * temp = front;
			QueueNode * prevTemp = front->prev;
			front = front->next;
			prevTemp->next = front;
			front->prev = prevTemp;
			delete temp;
			temp = NULL;
			prevTemp = NULL;
		}
	}

}


/******************************************************************************************
** Function: AddBack
** Description: This function adds an integer value to an empty node. If there aren't any 
**		empty nodes, this function will create a new node. 
** Parameters: Integer received to be added to queue. 
** Pre-Conditions: N/A
** Post-Conditons: A node in the queue will contain the passed integer. 
******************************************************************************************/
void Queue::addBack(int num) {

	if ((back == front) && (back->number == -1)) {
		cout << "The queue was previously empty" << endl;
		back->number = num;
	}

	else if ((back->next)->number == -1) {
		(back->next)->number = num;
		back = (back->next);
	}

	else if ((back->next) == front) {
		cout << "The queue is full, we must add another node" << endl;
		QueueNode * ptr = new QueueNode(num, front, back);
		(back->next) = ptr;
		(front->prev) = ptr;
		back = (back->next);
	}

	else {
		cout << "Something is wrong" << endl;
	}


}



/******************************************************************************************
** Function: getFront
** Description: This function returns the integer value of the integer at the front of the
**		queue (ie. the first integer added). If the queue is empty, this function will return
**		-1 (the sentinel value). 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: N/A
******************************************************************************************/
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



/******************************************************************************************
** Function: removedFront
** Description: This function removes the integer from the front of the Queue. Rather than 
**		deleting the node whose integer is removed, this function inserts the sentinel 
**		value of -1 (to indicate an empty node). If the queue is empty, the function will
**		return the sentinel value and display an error message. 
** Parameters: N/A
** Pre-Conditions: N/A
** Post-Conditons: This function will return the integer value of the emptied node. If the
**		Queue is empty, this function will return -1. 
******************************************************************************************/
int Queue::removeFront() {

	int removedInt;
	
	if ((front == back) && (front->number == -1)) {
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

