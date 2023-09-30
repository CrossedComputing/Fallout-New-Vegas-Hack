#pragma once
#include <Windows.h>
#include <vector>
#include "Address.h"
#include "InternalFunctions.h"


class Character {
private:

	std::vector<unsigned int> headCoordinateOffsets;
	std::vector<unsigned int> healthOffsets;

	IntAddress hostileAddress; // 1 = hostile
	FloatAddress healthAddress;
	Address BaseAddress;

	FloatAddress xCoordinateAddress;
	FloatAddress yCoordinateAddress;
	FloatAddress zCoordinateAddress;

	FloatAddress headXCoordinateAddress;
	FloatAddress headYCoordinateAddress;
	FloatAddress headZCoordinateAddress;

public:

	Character();

	Character(Address characterBaseAddress);

	bool IsAlive();

	/* Returns true if character is hostile.
	*/
	bool IsHostile();

	Address getAddress();
};

