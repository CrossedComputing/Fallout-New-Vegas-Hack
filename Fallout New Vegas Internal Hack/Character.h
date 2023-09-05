#pragma once
#include <Windows.h>
#include "Address.h"
#include <vector>
#include "InternalFunctions.h"

class Character
{
private:
	std::vector<unsigned int> headCoordinateOffsets;
	std::vector<unsigned int> healthOffsets;

	Address BaseAddress;
	FloatAddress xCoordinateAddress;
	FloatAddress yCoordinateAddress;
	FloatAddress zCoordinateAddress;
	IntAddress hostileAddress;
	FloatAddress healthAddress;
	FloatAddress headXCoordinateAddress;
	FloatAddress headYCoordinateAddress;
	FloatAddress headZCoordinateAddress;

public:
	Character();
	Character(Address characterBaseAddress);
	bool characterIsAlive();
	bool characterIsHostile();
};

