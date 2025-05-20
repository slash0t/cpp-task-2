#pragma once
#include "Stage.h"
class Simulation
{
private:
	bool finished;
	Stage* stage;
	Enviroment* enviroment;
public:
	Simulation();
	~Simulation();
	Enviroment* getEnviroment() const;
	bool isFinished() const;
	void performStage();
};

