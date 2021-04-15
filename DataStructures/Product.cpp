#include "Product.h"

Product::Product() {
	this->code = -1;
	this->name = "";
}

Product::Product(int code, std::string name) {
	this->code = code;
	this->name = name;
}

std::string Product::getName() const {
	return name;
}

int Product::getCode() const {
	return code;
}