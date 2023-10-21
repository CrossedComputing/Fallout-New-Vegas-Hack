#include "Character.h"


Character::Character() {
	this->BaseAddress = Address(0xDEADBEEF);
}

Character::Character(Address characterBaseAddress) {
	this->headCoordinateOffsets = { 0x1E0, 0x94 };
	this->healthOffsets = { 0x428, 0x84 };

	this->BaseAddress = characterBaseAddress;
	this->xCoordinateAddress = FloatAddress(characterBaseAddress.getAddress() + 0x34);
	this->yCoordinateAddress = FloatAddress(characterBaseAddress.getAddress() + 0x30);
	this->zCoordinateAddress = FloatAddress(characterBaseAddress.getAddress() + 0x38);
	this->hostileAddress = IntAddress(characterBaseAddress.getAddress() + 0x104);
	this->healthAddress = FloatAddress(InternalFunctions::resolvePointerChain(characterBaseAddress.getAddress() + 0x68, this->healthOffsets));
	this->headZCoordinateAddress = FloatAddress(InternalFunctions::resolvePointerChain(characterBaseAddress.getAddress() + 0x68, this->headCoordinateOffsets));
	this->headXCoordinateAddress = FloatAddress(headZCoordinateAddress.getAddress() - 0x4);
	this->headYCoordinateAddress = FloatAddress(headZCoordinateAddress.getAddress() - 0x8);
}

bool Character::IsHostile() {
	return this->hostileAddress.getValue() == 1;
}

Address Character::getAddress() {
	return this->BaseAddress;
}

bool Character::isAlive() {
	return this->healthAddress.getValue() > 0;
}

FloatAddress Character::getHeadXCoordinateAddress() {
	return this->headXCoordinateAddress;
}

FloatAddress Character::getHeadYCoordinateAddress() {
	return this->headYCoordinateAddress;
}

FloatAddress Character::getHeadZCoordinateAddress() {
	return this->headZCoordinateAddress;
}