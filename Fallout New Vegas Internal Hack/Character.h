#pragma once
#include <Windows.h>
#include <vector>
#include "Address.h"
#include "InternalFunctions.h"
#include <string>


/* Class for characters (NPCs)
* 
*/
class Character {
private:

	std::vector<std::string> crashCharacters;
	std::vector<unsigned int> headCoordinateOffsets;
	std::vector<unsigned int> healthOffsets;

	bool isValid;
	char name[50];

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

	/** If the character is found to be one that will crash the game
	*	by trying to calculate it's different properties, this will
	*	be set to true, and none of the character properties will be
	*	calculated for it.
	*/
	bool isCrashCharacter();

	/* Parses memory for the character's name.
	* 
	* The char* name passed in is pass by reference
	*/
	void computeCharacterName(char* name);

	void printName();

	/* Gets the base address of the character
	*/
	Address getAddress();

	FloatAddress getHeadXCoordinateAddress();

	FloatAddress getHeadYCoordinateAddress();

	FloatAddress getHeadZCoordinateAddress();
};

