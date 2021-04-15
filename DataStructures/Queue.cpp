#include "Queue.h"
#include "NodeType.h"
#include <iostream>

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	QueueNode* tempPointer;
	while (front != NULL) {
		tempPointer = front;
		front = front->next;
		delete tempPointer;
	}
	rear = NULL;
}

bool Queue::isFull() const
{
	QueueNode* location;
	try {
		location = new QueueNode;
		delete location;
		return false;
	}
	catch (std::bad_alloc exeption) {
		return true;
	}
}

bool Queue::isEmpty() const {
	return (front == NULL);
}

void Queue::enqueue(char itemInfo) {
	if (!isFull()) {
		QueueNode* node;
		node = new QueueNode;
		node->info = itemInfo;
		node->next = NULL;

		if (rear == NULL)
			front = node;
		else
			rear->next = node;

		rear = node;
	}
	else {
		throw "Queue is already full!";
	}
}

char Queue::dequeue() {
	if (!isEmpty()) {
		QueueNode* tempPointer;
		tempPointer = front;
		char itemInfo = front->info;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete tempPointer;
		return itemInfo;
	}
	else {
		throw "Queue is empty!";
	}
}

void Queue::print() const {
	QueueNode* tempPointer = front;
	while (tempPointer != NULL) {
		std::cout << tempPointer->info;
		tempPointer = tempPointer->next;
	}
	std::cout << std::endl;
}
