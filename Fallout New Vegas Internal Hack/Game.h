#pragma once
#include <Windows.h>
#include "Address.h"


class Game
{
public:
	Game();

	static Address getGameBaseAddress();
	static Address getEntityListAddress();

private:
	static Address gameBaseAddress;
	static Address entityListAddress;
};

