#pragma once
#include <Windows.h>
#include <vector>
#include "Address.h"
#include "InternalFunctions.h"


/* Class for characters (NPCs)
* 
* Currently, there is no need to refactor into subclasses like
*		human, animal, robot, etc because all of the entities appear to
*		have consistant structure in memory.
*/
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

	/* Default constructor will create a character with a base
	*		address of 0xDEADC0DE.
	*/
	Character();

	/* Constructor for the character class.
	* 
	* characterBaseAddress::address must contain the base address of a character.
	*/
	Character(Address characterBaseAddress);

	/* Returns true if character's health is greater than 0
	*/
	bool isAlive();

	/* Returns true if character is hostile.
	*/
	bool IsHostile();

	/* Returns true if character is a valid character.
	*		This method checks that the base address is not	
	*		0xDEADC0DE. It is Possible that a character is not
	*		valid if you mess up creating the entity list and try
	*		to create a character with a base address that isn't a 
	*		valid base address for a character.
	*/
	bool isValidCharacter();

	/* Gets the base address of the character
	*/
	Address getAddress();

	FloatAddress getHeadXCoordinateAddress();

	FloatAddress getHeadYCoordinateAddress();

	FloatAddress getHeadZCoordinateAddress();
};

