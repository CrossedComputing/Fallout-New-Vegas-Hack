#pragma once
#include <Windows.h>
#include "Address.h"


class Character
{
private:
	Address BaseAddress;
	Address writableXCoordinateAddress;
	Address writableYCoordinateAddress;
	Address writableZCoordinateAddress;
	Address NameAddress;
	Address hostileAddress;
	Address healthAddress;
	Address headXCoordinateAddress;
	Address headYCoordinateAddress;
	Address headZCoordinateAddress;

public:
	Character();
	Character(Address characterBaseAddress);
	bool characterIsAlive();
	bool characterIsHostile();
};

