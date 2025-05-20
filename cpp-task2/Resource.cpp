#include "Resource.h"

Resource::Resource(int healAmount) {
	this->healAmount = healAmount;
	this->used = false;
}

bool Resource::isUsed() const {
	return this->used;
}

int Resource::use(Robot* robot) {
	if (this->used) return 0;
	this->used = true;
	return robot->heal(this->healAmount);
}

int Resource::getHealAmount() const {
	return this->healAmount;
}
