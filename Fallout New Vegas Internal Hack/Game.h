#pragma once
#include <Windows.h>
#include "Address.h"


class Game
{
public:
	Game();

	/* Returns the static game address as an Address object
	*/
	static Address getGameBaseAddress();

	/* Returns the static entity list as an Address Object
	*/
	static Address getEntityListAddress();

private:
	static Address gameBaseAddress;
	static Address entityListAddress;
};

