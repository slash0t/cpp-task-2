#include "FighterStrategy.h"
#include "Robot.h"
#include "Location.h"
#include "Enviroment.h"
#include "ExplorerStrategy.h"

FighterStrategy::FighterStrategy() {
	this->explorer = new ExplorerStrategy();
}

void FighterStrategy::perform(Robot* robot, const Enviroment* enviroment) {
	Location* current = enviroment->getRobotLocation(robot);

	for (int i = 0; i < current->robotsCount(); i++) {
		Robot* enemy = current->getRobot(i);

		if (!enemy->isDead() && enemy->getClan() != robot->getClan()) {
			return;
		}
	}

	Location* next = nullptr;
	for (int i = 0; i < current->connectedLocationsCount(); i++) {
		Location* neighbor = current->getLocation(i);

		bool hasEnemy = false;

		for (int i = 0; i < neighbor->robotsCount(); i++) {
			Robot* enemy = neighbor->getRobot(i);

			if (!enemy->isDead() && enemy->getClan() != robot->getClan()) {
				hasEnemy = true;
			}
		}

		if (hasEnemy) {
			next = neighbor;
			break;
		}
	}

	if (next == nullptr) {
		this->explorer->perform(robot, enviroment);
	}
	else {
		this->explorer->updateLastLocation(current);

		this->moveRobot(robot, current, next);
	}
}