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
	FloatAddress rightArmHealthAddress;
	FloatAddress leftArmHealthAddress;
	FloatAddress rightLegHealthAddress;
	FloatAddress leftLegHealthAddress;
	std::vector<FloatAddress> bodyPartVector;

	FloatAddress xCoordinateAddress;
	FloatAddress yCoordinateAddress;
	FloatAddress zCoordinateAddress;
	FloatAddress pitchAddress;
	FloatAddress yawAddress;
	FloatAddress xHeadCoordinate;
	FloatAddress yHeadCoordinate;
	FloatAddress zHeadCoordinate;

	// Constructor for the Player class. 
	Player();

	/* Sets the player's health to 1000.0 and loops through the body part vector
	*  setting every body part's health to 1000.0.
	*/
	void godMode();
};

