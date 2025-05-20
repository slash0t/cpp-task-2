#include <iostream>
#include "Stage.h"

using namespace std;

Stage* FinishedStage::perform(Enviroment* enviroment) {
	cout << "Simultaion already finished" << endl;
	return new FinishedStage();
}
