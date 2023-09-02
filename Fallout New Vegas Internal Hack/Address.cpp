#include "Address.h"


/*
* INT
*/
IntAddress::IntAddress(uintptr_t address) {
	this->address = address;
}

int IntAddress::getValue() {
	return  *(int*)this->address;
}

void IntAddress::setValue(int newValue) {
	*(int*)this->address = newValue;
}

void IntAddress::printValue() {
	std::cout << "Value at " << std::hex << this->address << " " << std::dec << *(int*)this->address << std::endl;
}


/*
* FLOAT
*/
FloatAddress::FloatAddress(uintptr_t address) {
	this->address = address;
}

float FloatAddress::getValue() {
	return  *(float*)this->address;
}

void FloatAddress::setValue(float newValue) {
	*(float*)this->address = newValue;
}

void FloatAddress::printValue() {
	std::cout << "Value at " << std::hex << this->address << " " << std::dec << *(float*)this->address << std::endl;
}


/*
* DOUBLE
*/
DoubleAddress::DoubleAddress(uintptr_t address) {
	this->address = address;
}

double DoubleAddress::getValue() {
	return  *(double*)this->address;
}

void DoubleAddress::setValue(double newValue) {
	*(double*)this->address = newValue;
}

void DoubleAddress::printValue() {
	std::cout << "Value at " << std::hex << this->address << " " << std::dec << *(double*)this->address << std::endl;
}

