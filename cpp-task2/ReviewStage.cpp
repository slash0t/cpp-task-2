#include <iostream>
#include <set>

#include "Stage.h"

using namespace std;

Stage* ReviewStage::perform(Enviroment* enviroment) {
	cout << "Review stage started" << endl;

	set<int> aliveClans;

	int robotCount = enviroment->getRobotsCount();
	for (int i = 0; i < robotCount; i++) {
		auto robot = enviroment->getRobot(i);
		if (!robot->isDead()) {
			aliveClans.insert(robot->getClan());
		}
	}

	if (aliveClans.size() < 2) {
		cout << "Simulation finished" << endl;

		if (aliveClans.size() == 0) {
			cout << "No clans alive";
		}
		else {
			cout << "Won clan number " << *aliveClans.begin();
		}

		cout << endl << endl;

		return new FinishedStage();
	}
	else {
		cout << "Review stage ended with no result" << endl << endl;
		return new MovementStage();
	}
}
