#pragma once

#include <set>
#include <stack>
#include "Strategy.h"

class ExplorerStrategy : public MovementStrategy
{
private:
	std::set<Location*> visitedLocations;
	std::stack<Location*> lastVisitedLocation;
public:
	ExplorerStrategy();
	void Strategy::perform(Robot* robot, const Enviroment* enviroment);
	void updateLastLocation(Location* location);
};

