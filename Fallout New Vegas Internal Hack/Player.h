#pragma once
#include "Address.h"
#include "Game.h"
#include "InternalFunctions.h"
#include <vector>

class Player
{
public:

	std::vector<unsigned int> headOffsets;
	
	Address playerBaseAddress;
	IntAddress xpAddress;
	
	FloatAddress healthAddress;
	FloatAddress chestHealthAddress;
	FloatAddress headHealthAddress;
	FloatAddress leftArmHealthAddress;
	FloatAddress rightLegHealthAddress;
	FloatAddress leftLegHealthAddress;

	FloatAddress xCoordinateAddress;
	FloatAddress yCoordinateAddress;
	FloatAddress zCoordinateAddress;
	FloatAddress pitchAddress;
	FloatAddress yawAddress;
	FloatAddress xHeadCoordinate;
	FloatAddress yHeadCoordinate;
	FloatAddress zHeadCoordinate;

	Player();
};

