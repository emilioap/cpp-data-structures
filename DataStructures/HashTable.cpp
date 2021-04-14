#include "HashTable.h"
#include <iostream>

Hash::Hash(int max) {
	length = 0;
	maxItems = max;
	structure = new Student[maxItems];
}

Hash::~Hash() {
	delete[] structure;
}

bool Hash::isFull() const {
	return (length == maxItems);
}

void Hash::retrieveItem(Student& student, bool& found) {
	int location = getHash(student);
	Student aux = structure[location];
	if (student.getId() == aux.getId()) {
		found = true;
		student = aux;
	}
	else
		found = false;
}

void Hash::retrieveItemWithoutCollision(Student& student, bool& found) {
	int startLoc = getHash(student);
	bool needSearchMore = true;
	int location = startLoc;
	do {
		if (structure[location].getId() == student.getId() ||
			structure[location].getId() == -1)
			needSearchMore = false;
		else
			location = (location + 1) % maxItems;
	} while (location != startLoc && needSearchMore);

	found = (structure[location].getId() == student.getId());

	if (found) {
		student = structure[location];
	}
}

void Hash::insertItem(Student student) {
	bool found = false;
	int location = getHash(student);
	structure[location] = student;
	length++;
}

void Hash::insertItemWithoutCollision(Student student) {
	int location;
	location = getHash(student);
	while (structure[location].getId() > 0)
		location = (location + 1) % maxItems;
	structure[location] = student;
	length++;
}

void Hash::deleteItem(Student student) {
	int location = getHash(student);
	structure[location] = Student();
	length--;
}

void Hash::deleteItemWithoutCollision(Student student) {
	int startLoc = getHash(student);
	bool needSearchMore = true;
	int location = startLoc;
	do {
		if (structure[location].getId() == student.getId() || structure[location].getId() == -1)
			needSearchMore = false;
		else
			location = (location + 1) % maxItems;
	} while (location != startLoc && needSearchMore);

	if (structure[location].getId() == student.getId()) {
		structure[location] = Student(-2, "");
		length--;
	}
}

void Hash::print() const {
	std::cout << "Registered students: \n\n" << std::endl;
	for (int i = 0; i < maxItems; i++)
		std::cout << i << ":" << structure[i].getId() << ":" << structure[i].getName() << std::endl;
}

int Hash::getHash(Student student) {
	return student.getId() % maxItems;
}