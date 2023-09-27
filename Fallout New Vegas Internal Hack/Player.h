#pragma once
#include "Address.h"
#include "Game.h"
#include "InternalFunctions.h"
#include <vector>

class Player
{
public:	
	static Address playerBaseAddress;

	static IntAddress xpAddress;
	static FloatAddress healthAddress;

	static FloatAddress chestHealthAddress;
	static FloatAddress headHealthAddress;
	static FloatAddress rightArmHealthAddress;
	static FloatAddress leftArmHealthAddress;
	static FloatAddress rightLegHealthAddress;
	static FloatAddress leftLegHealthAddress;

	static std::vector<FloatAddress> bodyPartVector;

	static FloatAddress xCoordinateAddress;
	static FloatAddress yCoordinateAddress;
	static FloatAddress zCoordinateAddress;

	static FloatAddress xHeadCoordinate;
	static FloatAddress yHeadCoordinate;
	static FloatAddress zHeadCoordinate;

	static FloatAddress pitchAddress;
	static FloatAddress yawAddress;

	/* Sets the player's health to 1000.0 and loops through the body part vector
	*  setting every body part's health to 1000.0.
	*/
	static void godMode();

private:
	
	/* There will only be one player in the game.
	*	You do not need multiple player objects when
	*	the members and methods are static.
	*/
	Player();


	/* Only the player class will need to access this to find the head's
	*	coordinate address.
	*/
	static std::vector<unsigned int> headOffsets;

	/* Returns the Z coordinate address for the player's head.
	*/
	static FloatAddress getHeadZCoordinateAddress();
};

