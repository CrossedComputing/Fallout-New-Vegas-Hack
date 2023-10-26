#pragma once

#include <vector>
#include "Address.h"
#include "Player.h"
#include "Character.h"


/* The Aimbot class 
* 
*/
class Aimbot
{
public:

	/* This method calls all of the aimbot methods needed for the player
	*		to have aimbot. You will probably want to have this in dllmain.cpp's
	*		main loop.
	*/
	static void aimbot();

private:

	/* Gets the distance from the player to a character
	*		I recommend that you look up "3D distance formula"
	*		if you do not understand this code.
	*/
	static float getDistanceToPlayer(Character character);

	/* Gets the closest character to the player by
	*		iterating through the entity list and filtering
	*		by distance.
	*/
	static Character getClosestCharacter(std::vector<Character> entityList);

	/* Forces the player to aim at the head of the character.
	*/
	static void aimAt(Character character);
};

