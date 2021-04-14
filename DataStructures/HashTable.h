#pragma once
#include "Student.h"

class Hash {
public:
	Hash(int maxItems = 100);
	~Hash();
	bool isFull() const;
	int getLength() const;
	void retrieveItem(Student& student, bool& found);
	void retrieveItemWithoutCollision(Student& student, bool& found);
	void insertItem(Student student);
	void insertItemWithoutCollision(Student student);
	void deleteItem(Student student);
	void deleteItemWithoutCollision(Student student);
	void print() const;
private:
	int getHash(Student student);
	int maxItems;
	int length;
	Student* structure;
};