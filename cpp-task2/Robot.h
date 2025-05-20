#pragma once
#include <string>
#include "Strategy.h"

class Robot
{
private:
	std::string name;
	int startHp;
	int hp;
	int clan;
	MovementStrategy* movementStrategy;
	CombatStrategy* combatStrategy;
	ResourceStrategy* resourseStrategy;
protected:
	int baseDamage;
public:
	Robot(std::string name, int startHp, int baseDamage, int clan,
		MovementStrategy* movementStrategy, CombatStrategy* combatStrategy, ResourceStrategy* resourseStrategy);
	~Robot();

	bool isDead() const;
	int getHp() const;
	int getClan() const;
	std::string getName() const;
	std::string getInfo() const;

	virtual int countHealAmount(int amount) const;
	virtual int countDamageTaken(int amount) const;
	virtual int getDamage() const;

	int takeDamage(int amount);
	int heal(int amount);

	void move(const Enviroment* enviroment);
	void fight(const Enviroment* enviroment);
	void useResourses(const Enviroment* enviroment);
};

