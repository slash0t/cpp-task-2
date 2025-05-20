#pragma once
#include "Enviroment.h"
class Stage
{
public:
	virtual Stage* perform(Enviroment* enviroment) = 0;
};

class MovementStage : public Stage
{
public:
	Stage* perform(Enviroment* enviroment) override;
};

class ResourceStage : public Stage
{
public:
	Stage* perform(Enviroment* enviroment) override;
};

class CombatStage : public Stage
{
public:
	Stage* perform(Enviroment* enviroment) override;
};

class ReviewStage : public Stage
{
public:
	Stage* perform(Enviroment* enviroment) override;
};

class FinishedStage : public Stage
{
public:
	Stage* perform(Enviroment* enviroment) override;
};
