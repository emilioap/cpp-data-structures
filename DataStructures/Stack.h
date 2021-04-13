#pragma once

const int MAX_ITEMS = 100;

class Stack {
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	void print() const;
	void push(char);
	char pop();

private:
	int length;
	char* structure;
};