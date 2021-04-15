#pragma once
#include<iostream>

class Product {
private:
	int code;
	std::string name;
public:
	Product();
	Product(int code, std::string name);
	std::string getName() const;
	int getCode() const;
};