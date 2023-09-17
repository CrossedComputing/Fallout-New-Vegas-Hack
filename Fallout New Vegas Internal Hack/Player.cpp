#include "Player.h"


Player::Player() {
	this->playerBaseAddress = Address(Game::getGameBaseAddress().getAddress() + 0xDDEA3C);
}