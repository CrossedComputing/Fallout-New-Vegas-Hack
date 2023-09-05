#include "Game.h"


// Constructor 
Game::Game() {
	this->gameBaseAddress = Address((uintptr_t)GetModuleHandle("FalloutNV.exe"));
	this->entityListAddress = Address((gameBaseAddress.getAddress() + 0xDE0F00) + 0x8);
}

Address Game::getGameBaseAddress() {
	return this->gameBaseAddress;
}

Address Game::getEntityListAddress() {
	return this->entityListAddress;
}