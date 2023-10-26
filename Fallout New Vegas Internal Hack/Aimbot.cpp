#include "Aimbot.h"


float Aimbot::getDistanceToPlayer(Character character) {
	
	
	// first part of 3d distance formula
	float xDif = character.getHeadXCoordinateAddress().getValue() - Player::getHeadXCoordinateAddress().getValue();
	float yDif = character.getHeadYCoordinateAddress().getValue() - Player::getHeadYCoordinateAddress().getValue();
	float zDif = character.getHeadZCoordinateAddress().getValue() - Player::getHeadZCoordinateAddress().getValue();

	// second part of 3d distance formula
	float distance = sqrt((xDif * xDif) + (yDif * yDif) + (zDif * zDif));

	// return the distance
	return distance;
}


Character Aimbot::getClosestCharacter(std::vector<Character> entityList) {

	// Return a character with base address 0xDEADC0DE if entity list is empty.
	if (entityList.size() == 0) {
		Character character;
		return character;
	}

	float shortestDistance = FLT_MAX;
	float testingDistance = FLT_MAX;
	int closestCharacterIndex = 0;
	

	for (size_t i = 0; i < entityList.size(); i++) {
		testingDistance = Aimbot::getDistanceToPlayer(entityList[i]);
		if (testingDistance < shortestDistance) {
			shortestDistance = testingDistance;
			closestCharacterIndex = i;
		}
	}
	return entityList[closestCharacterIndex];
}


void Aimbot::aimAt(Character character) {

	if (!character.isValidCharacter()) {
		return;
	}

	float xDif = character.getHeadXCoordinateAddress().getValue() - Player::getHeadXCoordinateAddress().getValue();
	float yDif = character.getHeadYCoordinateAddress().getValue() - Player::getHeadYCoordinateAddress().getValue();
	float zDif = character.getHeadZCoordinateAddress().getValue() - Player::getHeadZCoordinateAddress().getValue();


	float hypotenuse = sqrt((xDif * xDif) + (yDif * yDif) + (zDif * zDif));
	float opposite = zDif;

	float yaw = atan2(yDif, xDif);

	float pitch = asin(opposite / hypotenuse);


	// We have to prefix asin with a negative here because looking up in new vegas is Negative pitch
	// Looking down is positive pitch (This is going to be game dependent. NV just happens to use
	// Up - Negative | Down - Positive
	Player::setPlayerPitch(-pitch);
	Player::setPlayerYaw(yaw);
}

void Aimbot::aimbot() {
	Character closestCharacter = Aimbot::getClosestCharacter(Game::getEntityList());

	if (GetAsyncKeyState(VK_RBUTTON)) {
		Aimbot::aimAt(closestCharacter);
	}
}