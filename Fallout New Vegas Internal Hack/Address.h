#pragma once
#include <iostream>
#include <Windows.h>



// Base Class
class Address
{
protected:
	uintptr_t address;
public:
	Address();
	Address(uintptr_t memoryAddress);
	uintptr_t getAddress();
};

class IntAddress : Address {
public:

	IntAddress(uintptr_t address);

	int getValue();

	void setValue(int newValue);

	void printValue();
};

class FloatAddress : Address {
public:

	FloatAddress(uintptr_t address);

	float getValue();

	void setValue(float newValue);

	void printValue();
};

class DoubleAddress : Address {
public:

	DoubleAddress(uintptr_t address);

	double getValue();

	void setValue(double newValue);

	void printValue();
};
