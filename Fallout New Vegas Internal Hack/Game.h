#pragma once
#include <Windows.h>
#include "Address.h"


class Game
{
private:
	Address gameBaseAddress;
	Address entityListAddress;

public:
	Game();

	Address getGameBaseAddress();

	Address getEntityListAddress();
};

