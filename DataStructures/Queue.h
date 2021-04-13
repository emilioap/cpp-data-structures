#pragma once
#include "NodeType.h"

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
	NodeType* front;
	NodeType* rear;
};