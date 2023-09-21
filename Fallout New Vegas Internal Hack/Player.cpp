#include "Player.h"


Player::Player() {
	this->playerBaseAddress = Address(Game::getGameBaseAddress().getAddress() + 0xDDEA3C).dereference();;
	this->xpAddress = IntAddress(Player::playerBaseAddress.getAddress() + 0x3D8);
	this->healthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x4AC);
	this->chestHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x518);
	this->headHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x514);
	this->rightArmHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x51C);
	this->leftArmHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x520);
	this->rightLegHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x524);
	this->leftArmHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x528);
	this->xCoordinateAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x34);
	this->yCoordinateAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x30);
	this->xCoordinateAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x38);
	this->pitchAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x24);
	this->yawAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x2C);


	/*
	FloatAddress xHeadCoordinate;
	FloatAddress yHeadCoordinate;
	FloatAddress zHeadCoordinate;
	*/
}