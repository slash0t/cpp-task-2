#include "Robot.h"
#include <string>;

using namespace std;

Robot::Robot(string name, int startHp, int baseDamage, int clan,
	MovementStrategy* movementStrategy, CombatStrategy* combatStrategy, ResourceStrategy* resourseStrategy) {
	this->name = name;
	this->hp = startHp;
	this->startHp = startHp;
	this->baseDamage = baseDamage;
	this->clan = clan;

	this->movementStrategy = movementStrategy;
	this->combatStrategy = combatStrategy;
	this->resourseStrategy = resourseStrategy;
}

Robot::~Robot() {
	delete this->movementStrategy;
	delete this->combatStrategy;
	delete this->resourseStrategy;
}

bool Robot::isDead() const {
	return this->hp == 0;
}

int Robot::getHp() const {
	return this->hp;
}

int Robot::getClan() const {
	return this->clan;
}

string Robot::getName() const {
	return this->name;
}

string Robot::getInfo() const {
	return this->name + "(" + to_string(this->hp) + "/" + to_string(this->startHp) + ")";
}

int Robot::takeDamage(int amount) {
	int dealtDamage = min(this->hp, this->countDamageTaken(amount));
	this->hp -= dealtDamage;
	return dealtDamage;
}

int Robot::heal(int amount) {
	if (this->isDead()) return 0;

	int healAmount = min(this->startHp - this->hp, amount);

	this->hp += healAmount;

	return healAmount;
}

int Robot::countHealAmount(int amount) const {
	return amount;
}

int Robot::countDamageTaken(int amount) const {
	return amount;
}

int Robot::getDamage() const {
	return this->baseDamage;
}

void Robot::move(const Enviroment* enviroment) {
	this->movementStrategy->perform(this, enviroment);
}

void Robot::fight(const Enviroment* enviroment) {
	this->combatStrategy->perform(this, enviroment);
}

void Robot::useResourses(const Enviroment* enviroment) {
	this->resourseStrategy->perform(this, enviroment);
}
