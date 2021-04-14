#include "Student.h"

Student::Student() {
	this->id = -1;
	this->name = "";
}

Student::Student(int id, std::string name) {
	this->id = id;
	this->name = name;
}

std::string Student::getName() const {
	return name;
}

int Student::getId() const {
	return id;
}
