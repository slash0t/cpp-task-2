#pragma once

#include <iostream>
#include "Strategy.h"
#include "Robot.h"
#include "Resource.h"

using namespace std;

void ResourceStrategy::useResource(Robot* robot, Resource* resource) {
	if (robot->isDead() || resource->isUsed()) {
		return;
	}

	int healAmount = resource->use(robot);

	cout << "Robot " << robot->getInfo() << " healed " << healAmount << " hp" << endl;
}