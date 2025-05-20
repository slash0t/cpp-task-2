#include "FinisherStrategy.h"
#include "Robot.h"
#include "Location.h"
#include "Enviroment.h"

FinisherStrategy::FinisherStrategy() {}

void FinisherStrategy::perform(Robot* robot, const Enviroment* enviroment) {
	Location* current = enviroment->getRobotLocation(robot);

	Robot* minHpEnemy = nullptr;
	for (int i = 0; i < current->robotsCount(); i++) {
		Robot* enemy = current->getRobot(i);

		if (enemy->isDead() || enemy->getClan() == robot->getClan()) {
			continue;
		}

		if (minHpEnemy == nullptr || minHpEnemy->getHp() > enemy->getHp()) {
			minHpEnemy = enemy;
		}
	}

	if (minHpEnemy != nullptr) {
		this->attack(robot, minHpEnemy);
	}
}