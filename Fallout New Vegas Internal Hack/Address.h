#pragma once
#include <iostream>
#include <Windows.h>



// Base Class
class Address
{
protected:
	uintptr_t address;
public:
	/* Default constructor
	*/
	Address();

	/* Constructor that takes in a memory address (uintptr_t)
	*/
	Address(uintptr_t memoryAddress);

	/* Returns the address (uintptr_t)
	*/
	uintptr_t getAddress();

	/* Dereferences the current address but does not re-assign this->address
	*/
	uintptr_t dereference();
};

class IntAddress : public Address {
public:
	IntAddress();
	IntAddress(uintptr_t address);

	int getValue();

	void setValue(int newValue);

	void printValue();
};

class FloatAddress : public Address {
public:
	FloatAddress();
	FloatAddress(uintptr_t address);

	float getValue();

	void setValue(float newValue);

	void printValue();
};

class DoubleAddress : public Address {
public:

	DoubleAddress(uintptr_t address);

	double getValue();

	void setValue(double newValue);

	void printValue();
};
