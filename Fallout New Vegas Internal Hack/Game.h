#pragma once
#include <Windows.h>
#include <vector>
#include "Address.h"
#include "Character.h"


/* Game address for generic game addresses and methods.
*/
class Game
{
public:

	/* Returns the game's base address as an Address object
	*/
	static Address getGameBaseAddress();

	/* Returns the entity list as an Address Object
	*/
	static Address getEntityListAddress();

	/* Returns the entity list as a vector of Characters
	*/
	static std::vector<Character> getEntityList();

private:

	/* Constructor is private because there is only one "game".
	*	You do not need to create a game object, everything can be
	*	accessed statically.
	*/
	Game();

	/* gameBaseAddress needs to be not bound to a class instance
	*/
	static Address gameBaseAddress;

	/* entityListAddress needs to be not bound to a class instance
	*/
	static Address entityListAddress;
};

