#include "Game.h"


Address Game::gameBaseAddress = Address((uintptr_t)GetModuleHandle("FalloutNV.exe"));
Address Game::entityListAddress = Address((gameBaseAddress.getAddress() + 0xDE0F00) + 0x8);


Game::Game() {

}

Address Game::getGameBaseAddress() {
	return Game::gameBaseAddress;
}

Address Game::getEntityListAddress() {
	return Game::entityListAddress;
}