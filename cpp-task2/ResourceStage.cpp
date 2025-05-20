#pragma once

#include <iostream>
#include "Stage.h"

using namespace std;

Stage* ResourceStage::perform(Enviroment* enviroment) {
	cout << "Resource stage started" << endl;

	int robotCount = enviroment->getRobotsCount();
	for (int i = 0; i < robotCount; i++) {
		auto robot = enviroment->getRobot(i);
		if (!robot->isDead()) {
			robot->useResourses(enviroment);
		}
	}

	cout << "Resource stage ended" << endl << endl;
	return new ReviewStage();
}
