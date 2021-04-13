#include "Queue.h"
#include "NodeType.h"
#include <iostream>

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	NodeType* tempPointer;
	while (front != NULL) {
		tempPointer = front;
		front = front->next;
		delete tempPointer;
	}
	rear = NULL;
}

bool Queue::isFull() const
{
	NodeType* location;
	try {
		location = new NodeType;
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
		NodeType* node;
		node = new NodeType;
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
		NodeType* tempPointer;
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
	NodeType* tempPointer = front;
	while (tempPointer != NULL) {
		std::cout << tempPointer->info;
		tempPointer = tempPointer->next;
	}
	std::cout << std::endl;
}
