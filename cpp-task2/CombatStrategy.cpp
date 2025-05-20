#pragma once 

#include "Strategy.h"
#include "Robot.h"
#include <iostream>

using namespace std;

void CombatStrategy::attack(const Robot* attacker, Robot* defendant) {
	int damageAttacked = attacker->getDamage();
	int damageTaken = defendant->countDamageTaken(damageAttacked);
	int damageDealt = defendant->takeDamage(damageTaken);

	cout << "Robot " << attacker->getInfo() << " dealt " << damageDealt << " damage to robot " << defendant->getInfo() << endl;
	if (defendant->isDead()) {
		cout << "Robot " << defendant->getName() << " died" << endl;
	}
}