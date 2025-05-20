#include "Location.h"

Location::Location(string name) : connectedLocations(), resources(), robots() {
	this->name = name;
}

int Location::connectedLocationsCount() const {
	return this->connectedLocations.size();
}

int Location::resourcesCount() const {
	return this->resources.size();
}

int Location::robotsCount() const {
	return this->robots.size();
}

Location* Location::getLocation(int index) const {
	return this->connectedLocations[index];
}

Resource* Location::getResource(int index) const {
	return this->resources[index];
}

Robot* Location::getRobot(int index) const {
	return this->robots[index];
}

string Location::getName() const {
	return this->name;
}

bool Location::containsRobot(const Robot* const robot) const {
	bool contains = false;
	for (auto otherRobot : this->robots) {
		if (otherRobot == robot) {
			contains = 1;
		}
	}
	return contains;
}

void Location::addLocation(Location* location) {
	this->connectedLocations.push_back(location);
}

void Location::addResource(Resource* resource) {
	this->resources.push_back(resource);
}

void Location::addRobot(Robot* robot) {
	this->robots.push_back(robot);
}

void Location::removeLocation(Location* location) {
	this->connectedLocations.erase(
		std::remove(
			this->connectedLocations.begin(), this->connectedLocations.end(), location
		),
		this->connectedLocations.end()
	);
}

void Location::removeRobot(Robot* robot) {
	this->robots.erase(
		std::remove(
			this->robots.begin(), this->robots.end(), robot
		),
		this->robots.end()
	);
}
