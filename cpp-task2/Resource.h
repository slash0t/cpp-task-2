#pragma once

#include "Robot.h"

class Resource
{
private:
	int healAmount;
	bool used;
public:
	Resource(int healAmount);
	bool isUsed() const;
	int use(Robot* robot);
	int getHealAmount() const;
};
