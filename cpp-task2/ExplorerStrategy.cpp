#include <stack>
#include "ExplorerStrategy.h"
#include "Robot.h"
#include "Enviroment.h"
#include "Location.h"

ExplorerStrategy::ExplorerStrategy() : visitedLocations(), lastVisitedLocation() {}

void ExplorerStrategy::perform(Robot* robot, const Enviroment* enviroment) {
	Location* current = enviroment->getRobotLocation(robot);

	this->visitedLocations.insert(current);

	Location* next = nullptr;
	for (int i = 0; i < current->connectedLocationsCount(); i++) {
		Location* neighbor = current->getLocation(i);

		if (!visitedLocations.count(neighbor)) {
			next = neighbor;
			break;
		}
	}

	if (next == nullptr) {
		if (this->lastVisitedLocation.empty()) {
			return;
		}
		else {
			next = this->lastVisitedLocation.top();
			this->lastVisitedLocation.pop();
		}
	}
	else {
		this->updateLastLocation(current);
	}
	
	this->moveRobot(robot, current, next);
}

void ExplorerStrategy::updateLastLocation(Location* location) {
	this->lastVisitedLocation.push(location);
	this->visitedLocations.insert(location);
}
