#pragma once
#include "Simulation.h"
#include "Strategy.h"
#include <typeinfo>

Simulation::Simulation() {
	this->finished = 0;
	this->stage = new MovementStage();
	this->enviroment = new Enviroment();
}

Simulation::~Simulation() {
	delete this->enviroment;
	delete this->stage;
}

Enviroment* Simulation::getEnviroment() const {
	return this->enviroment;
}

void Simulation::performStage() {
	Stage* nextStage = this->stage->perform(this->enviroment);
	delete this->stage;
	this->stage = nextStage;

	if (nullptr != dynamic_cast<FinishedStage*>(this->stage)) {
		finished = 1;
	}
}

bool Simulation::isFinished() const {
	return finished;
}