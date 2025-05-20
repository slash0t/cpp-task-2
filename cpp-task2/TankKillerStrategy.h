#pragma once

#include "Strategy.h"

class TankKillerStrategy : public CombatStrategy
{
public:
	TankKillerStrategy();
	void Strategy::perform(Robot* robot, const Enviroment* enviroment);
};

