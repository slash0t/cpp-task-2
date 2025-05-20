#pragma once
#include <vector>
#include "Robot.h"

class Enviroment
{
private:
	std::vector<Robot*> robots;
	std::vector<Location*> locations;
public:
	Enviroment();
	~Enviroment();

	int getRobotsCount() const;
	int getLocationsCount() const;

	Robot* getRobot(int index) const;
	Location* getLocation(int index) const;
	Location* getRobotLocation(const Robot* const robot) const;

	void addRobot(Robot* robot);
	void addLocation(Location* location);

	void connectLocations(Location* location1, Location* location2);

	void removeRobot(Robot* robot);
	void removeLocation(Location* location);
};

