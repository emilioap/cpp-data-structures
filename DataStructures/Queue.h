#pragma once
#include "QueueNode.h"

class Queue {
public:
	Queue();
	~Queue();
	bool isEmpty() const;
	bool isFull() const;
	void print() const;
	void enqueue(char);
	char dequeue();

private:
	QueueNode* front;
	QueueNode* rear;
};