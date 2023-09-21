#include "Address.h"


// BASE
// Default constructor
Address::Address() {
	this->address = 0xDEADBEEF;
}

// Main Constructor
Address::Address(uintptr_t memoryAddress) {
	this->address = memoryAddress;
}


uintptr_t Address::getAddress() {
	return this->address;
}

uintptr_t Address::dereference() {
	return *(uintptr_t*)this->address;
}


/*
* INT
*/
IntAddress::IntAddress() { this->address = 0xDEADBEEF; }
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
FloatAddress::FloatAddress() { this->address = 0xDEADBEEF; }
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

