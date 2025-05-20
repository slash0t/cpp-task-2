#pragma once

#include "Strategy.h"
#include "ExplorerStrategy.h"

class FighterStrategy : public MovementStrategy
{
private:
	ExplorerStrategy* explorer;
public:
	FighterStrategy();
	void Strategy::perform(Robot* robot, const Enviroment* enviroment);
};
