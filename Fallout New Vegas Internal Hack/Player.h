#pragma once
#include "Address.h"
#include "Game.h"
#include "InternalFunctions.h"
#include <vector>

class Player
{
private:
	
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
	static std::vector<unsigned int> headOffsets;


	static FloatAddress pitchAddress;
	static FloatAddress yawAddress;

	static Address gravityInstructionAddress;

	static char gravitySignature[7];
	static char gravityMask[7];



	/* There will only be one player in the game.
	*		You do not need multiple player objects when
	*		the members and methods are static.
	*/
	Player();

	/* Resolve the pointer chain to the gravity address for the player
	*/
	static Address resolvePointerChainToGravityInstruction();



public:

	/* Getter for the gravity instruction address
	*/
	static Address getGravityInstruction();

	/* Resolves the pointer chain leading to the player's head's Z
	*		coordinate.
	*/
	static FloatAddress resolveHeadZCoordAddress();

	/* Returns an Address object containing the player's head's X
	*		coordinates.
	*/
	static FloatAddress getHeadXCoordinateAddress();

	/* Returns an Address object containing the player's head's Y
	*		coordinates.
	*/
	static FloatAddress getHeadYCoordinateAddress();

	/* Returns an Address object containing the player's head's Z
	*		coordinates.
	*/
	static FloatAddress getHeadZCoordinateAddress();

	/* Set a new yaw for the player's view
	*/
	static void setPlayerYaw(float yaw);

	/* Set a new pitch for the player's view
	*/
	static void setPlayerPitch(float pitch);

	/* Sets the player's health to 1000.0 and loops through the body part vector
	*		setting every body part's health to 1000.0.
	*/
	static void godMode();
};

