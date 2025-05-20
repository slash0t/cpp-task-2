#include <iostream>
#include "Stage.h"

using namespace std;

Stage* MovementStage::perform(Enviroment* enviroment) {
	cout << "Movement stage started" << endl;
	int robotCount = enviroment->getRobotsCount();
	for (int i = 0; i < robotCount; i++) {
		auto robot = enviroment->getRobot(i);
		if (!robot->isDead()) {
			robot->move(enviroment);
		}
	}
	cout << "Movement stage ended" << endl << endl;
	return new CombatStage();
}