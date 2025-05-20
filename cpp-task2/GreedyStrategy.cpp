#include "GreedyStrategy.h"
#include "Robot.h"
#include "Location.h"
#include "Enviroment.h"

GreedyStrategy::GreedyStrategy() {}

void GreedyStrategy::perform(Robot* robot, const Enviroment* enviroment) {
	Location* current = enviroment->getRobotLocation(robot);

	Resource* best = nullptr;
	for (int i = 0; i < current->resourcesCount(); i++) {
		Resource* resource = current->getResource(i);

		if (resource->isUsed()) continue;

		if (best == nullptr || best->getHealAmount() < resource->getHealAmount()) {
			best = resource;
		}
	}

	if (best != nullptr) {
		useResource(robot, best);
	}
}