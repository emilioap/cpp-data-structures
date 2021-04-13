#include "Stack.h"
#include <iostream>

Stack::Stack() {
	length = 0;
	structure = new char[MAX_ITEMS];
}

Stack::~Stack() {
	delete [] structure;
}

bool Stack::isEmpty() const {
	return (length == 0);
}

bool Stack::isFull() const {
	return (length == MAX_ITEMS);
}

void Stack::push(char item) {
	if (!isFull()) {
		structure[length] = item;
		length++;
	}
	else {
		throw "Stack is already full!";
	}
}

char Stack::pop() {
	if (!isEmpty()) {
		char aux = structure[length - 1];
		length--;
		return aux;
	}
	else {
		throw "Stack is already empty!";
	}
}

void Stack::print() const {
	std::cout << "Stack: ";
	for (int i = 0; i < length; i++) {
		std::cout << structure[i];
	}
	std::cout << std::endl;
}