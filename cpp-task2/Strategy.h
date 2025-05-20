#pragma once

class Robot;
class Location;
class Resource;
class Enviroment;

class Strategy
{
public:
	virtual void perform(Robot* robot, const Enviroment* enviroment) = 0;
};

class MovementStrategy : public Strategy
{
public:
	void moveRobot(Robot* robot, Location* from, Location* to);
};

class ResourceStrategy : public Strategy
{
public:
	void useResource(Robot* robot, Resource* resource);
};

class CombatStrategy : public Strategy
{
public:
	void attack(const Robot* attacker, Robot* defendant);
};