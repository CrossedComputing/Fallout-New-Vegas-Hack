#include "Character.h"


Character::Character() {
	this->BaseAddress = Address(0xDEADC0DE);
	this->isValid = false;
}

Character::Character(Address characterBaseAddress) {
	this->BaseAddress = characterBaseAddress;

	this->headCoordinateOffsets = { 0x1E0, 0x94 };
	this->healthOffsets = { 0x428, 0x84 };
	this->crashCharacters.push_back("Raven");

	Character::computeCharacterName(this->name);

	this->isValid = !Character::isCrashCharacter();

	if (this->isValid == true) {
		this->xCoordinateAddress = FloatAddress(characterBaseAddress.getAddress() + 0x34);
		this->yCoordinateAddress = FloatAddress(characterBaseAddress.getAddress() + 0x30);
		this->zCoordinateAddress = FloatAddress(characterBaseAddress.getAddress() + 0x38);
		this->hostileAddress = IntAddress(characterBaseAddress.getAddress() + 0x104);
		this->healthAddress = FloatAddress(InternalFunctions::resolvePointerChain(characterBaseAddress.getAddress() + 0x68, this->healthOffsets));
		this->headZCoordinateAddress = FloatAddress(InternalFunctions::resolvePointerChain(characterBaseAddress.getAddress() + 0x68, this->headCoordinateOffsets));
		this->headXCoordinateAddress = FloatAddress(headZCoordinateAddress.getAddress() - 0x4);
		this->headYCoordinateAddress = FloatAddress(headZCoordinateAddress.getAddress() - 0x8);
	}
	else {
		this->BaseAddress = Address(0xDEADC0DE);
	}
}

bool Character::IsHostile() {
	if (this->isValid) {
		return this->hostileAddress.getValue() == 1;
	}
	else {
		return false;
	}
}

bool Character::isAlive() {
	if (this->isValid) {
		return this->healthAddress.getValue() > 0;
	}
	else {
		return false;
	}
}

bool Character::isValidCharacter() {
	return this->isValid;
}

bool Character::isCrashCharacter() {
	for (size_t i = 0; i < this->crashCharacters.size(); i++) {
		if (this->crashCharacters.at(i) == this->name) {
			return true;
		}
	}
	return false;
}

void Character::computeCharacterName(char* name) {
	int index = 0;

	std::vector<unsigned int> nameOffsets = { 0xD4, 0x0 };
	CharAddress characterNameAddress = InternalFunctions::resolvePointerChain(this->BaseAddress.getAddress() + 0x20, nameOffsets);

	while (characterNameAddress.getValue() != '\0' && index < 50) {
		name[index] = characterNameAddress.getValue();
		characterNameAddress.incrementAddress(0x1);
		index += 1;
	}
}

void Character::printName() {
	std::cout << "Character " << std::hex << this->BaseAddress.getAddress() << ": " << this->name << std::endl;
}

Address Character::getAddress() {
	return this->BaseAddress;
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