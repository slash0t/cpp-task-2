#include <iostream>
#include "Stage.h"

using namespace std;

Stage* CombatStage::perform(Enviroment* enviroment) {
	cout << "Combat stage started" << endl;
	int robotCount = enviroment->getRobotsCount();
	for (int i = 0; i < robotCount; i++) {
		auto robot = enviroment->getRobot(i);
		if (!robot->isDead()) {
			robot->fight(enviroment);
		}
	}
	cout << "Combat stage ended" << endl << endl;
	return new ResourceStage();
}
