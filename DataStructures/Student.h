#pragma once
#include<iostream>

class Student {
private:
	int id;
	std::string name;
public:
	Student();
	Student(int id, std::string name);
	std::string getName() const;
	int getId() const;
};