#pragma once
#include <vector>
#include <string>

#include "Resource.h"
#include "Robot.h"

using namespace std;

class Location
{
private:
	string name;
	vector<Location*> connectedLocations;
	vector<Resource*> resources;
	vector<Robot*> robots;
public:
	Location(string name);

	int connectedLocationsCount() const;
	int resourcesCount() const;
	int robotsCount() const;

	Location* getLocation(int index) const;
	Resource* getResource(int index) const;
	Robot* getRobot(int index) const;
	string getName() const;

	bool containsRobot(const Robot* robot) const;

	void addLocation(Location* location);
	void addResource(Resource* resource);
	void addRobot(Robot* robot);

	void removeLocation(Location* location);
	void removeRobot(Robot* robot);
};

