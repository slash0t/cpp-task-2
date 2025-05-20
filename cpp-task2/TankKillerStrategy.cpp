#include "TankKillerStrategy.h"
#include "Robot.h"
#include "Enviroment.h"
#include "Location.h"

TankKillerStrategy::TankKillerStrategy() {}

void TankKillerStrategy::perform(Robot* robot, const Enviroment* enviroment) {
	Location* current = enviroment->getRobotLocation(robot);

	Robot* maxHpEnemy = nullptr;
	for (int i = 0; i < current->robotsCount(); i++) {
		Robot* enemy = current->getRobot(i);

		if (enemy->isDead() || enemy->getClan() == robot->getClan()) {
			continue;
		}

		if (maxHpEnemy == nullptr || maxHpEnemy->getHp() < enemy->getHp()) {
			maxHpEnemy = enemy;
		}
	}

	if (maxHpEnemy != nullptr) {
		this->attack(robot, maxHpEnemy);
	}
}