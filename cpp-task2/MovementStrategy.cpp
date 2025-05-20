#pragma once

#include <iostream>
#include "Strategy.h"
#include "Robot.h"
#include "Location.h"

using namespace std;

void MovementStrategy::moveRobot(Robot* robot, Location* from, Location* to) {
	from->removeRobot(robot);
	to->addRobot(robot);

	cout << "Robot " << robot->getInfo() << " moved from " << from->getName() << " to " << to->getName() << endl;
}