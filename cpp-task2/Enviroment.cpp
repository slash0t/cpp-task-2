#include "Enviroment.h"
#include "Location.h"

Enviroment::Enviroment() : robots(), locations() {}

Enviroment::~Enviroment() {
	for (Robot* robot : robots) {
		delete robot;
	}
	for (Location* location : locations) {
		delete location;
	}
}

int Enviroment::getRobotsCount() const {
	return this->robots.size();
}

int Enviroment::getLocationsCount() const {
	return this->locations.size();
}

Robot* Enviroment::getRobot(int index) const {
	return this->robots[index];
}

Location* Enviroment::getLocation(int index) const {
	return this->locations[index];
}

Location* Enviroment::getRobotLocation(const Robot* const robot) const {
	Location* resultLocation = nullptr;

	for (auto location : this->locations) {
		if (location->containsRobot(robot)) {
			resultLocation = location;
		}
	}
	return resultLocation;
}

void Enviroment::addRobot(Robot* robot) {
	this->robots.push_back(robot);
}

void Enviroment::addLocation(Location* location) {
	this->locations.push_back(location);
}

void Enviroment::connectLocations(Location* location1, Location* location2) {
	location1->addLocation(location2);
	location2->addLocation(location1);
}

void Enviroment::removeRobot(Robot* robot) {
	for (Location* location : this->locations) {
		location->removeRobot(robot);
	}
	this->robots.erase(
		std::remove(
			this->robots.begin(), this->robots.end(), robot
		),
		this->robots.end()
	);
}

void Enviroment::removeLocation(Location* location) {
	this->locations.erase(
		std::remove(
			this->locations.begin(), this->locations.end(), location
		),
		this->locations.end()
	);
	for (Location* otherLocation : this->locations) {
		otherLocation->removeLocation(otherLocation);
	}
}
