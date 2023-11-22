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

void Game::printEntityList() {
	for (size_t i = 0; i < Game::getEntityList().size(); i++) {
		Game::getEntityList()[i].printName();
	}
}

std::vector<Character> Game::getEntityList() {
	std::vector<Character> entityList;
	Address characterBuffer;
	Address entityListPosition(Game::entityListAddress);

	while (entityListPosition.dereference() != 0) {
		Address characterAddress(entityListPosition.dereference());
		Character character(characterAddress);

		if (character.isValidCharacter() && character.isAlive()) {
			entityList.push_back(character);
		}
		entityListPosition.add(0x4);
	}
	return entityList;
}