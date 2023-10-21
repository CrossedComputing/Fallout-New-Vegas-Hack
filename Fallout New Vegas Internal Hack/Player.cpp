#include "Player.h"


Address Player::playerBaseAddress = Address(Game::getGameBaseAddress().getAddress() + 0xDDEA3C).dereference();;

IntAddress Player::xpAddress = IntAddress(Player::playerBaseAddress.getAddress() + 0x3D8);
FloatAddress Player::healthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x4AC);

FloatAddress Player::chestHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x518);
FloatAddress Player::headHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x514);
FloatAddress Player::rightArmHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x51C);
FloatAddress Player::leftArmHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x520);
FloatAddress Player::rightLegHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x524);
FloatAddress Player::leftLegHealthAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x528);
std::vector<FloatAddress> Player::bodyPartVector = { Player::chestHealthAddress, Player::headHealthAddress, Player::rightArmHealthAddress,
	Player::leftArmHealthAddress, Player::rightLegHealthAddress, Player::leftLegHealthAddress };

FloatAddress Player::xCoordinateAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x34);
FloatAddress Player::yCoordinateAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x30);
FloatAddress Player::zCoordinateAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x38);

FloatAddress Player::pitchAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x24);
FloatAddress Player::yawAddress = FloatAddress(Player::playerBaseAddress.getAddress() + 0x2C);

std::vector<unsigned int> Player::headOffsets = { 0x44, 0x94 };
FloatAddress Player::zHeadCoordinate = Player::resolveHeadZCoordAddress();
FloatAddress Player::xHeadCoordinate = FloatAddress(Player::zHeadCoordinate.getAddress() - 0x4);
FloatAddress Player::yHeadCoordinate = FloatAddress(Player::zHeadCoordinate.getAddress() - 0x8);



void Player::godMode() {
	Player::healthAddress.setValue(1000.0);

	for (unsigned int i = 0; i < Player::bodyPartVector.size(); i++) {
		Player::bodyPartVector[i].setValue(1000.0);
	}
}

FloatAddress Player::resolveHeadZCoordAddress() {
	return InternalFunctions::resolvePointerChain(Player::playerBaseAddress.getAddress() + 0x690, Player::headOffsets);
}

FloatAddress Player::getHeadXCoordinateAddress() {
	return Player::xHeadCoordinate;
}

FloatAddress Player::getHeadYCoordinateAddress() {
	return Player::yHeadCoordinate;
}

FloatAddress Player::getHeadZCoordinateAddress() {
	return Player::zHeadCoordinate;
}

void Player::setPlayerYaw(float yaw) {
	Player::yawAddress.setValue(yaw);
}

void Player::setPlayerPitch(float pitch) {
	Player::pitchAddress.setValue(pitch);
}