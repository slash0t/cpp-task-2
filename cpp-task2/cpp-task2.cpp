#include "Strategy.h"
#include "Robot.h"
#include "Resource.h"
#include "Location.h"
#include "Simulation.h"
#include "Enviroment.h"
#include "ExplorerStrategy.h"
#include "FighterStrategy.h"
#include "FinisherStrategy.h"
#include "GreedyStrategy.h"
#include "IgnorerStrategy.h"
#include "TankKillerStrategy.h"


int main()
{
    Location* location1 = new Location("Spawn1");
    Location* location2 = new Location("Spawn2");
    Location* location3 = new Location("Middle");

    Robot* robot1 = new Robot("Robot1", 10, 3, 1, new ExplorerStrategy(), new TankKillerStrategy(), new GreedyStrategy());
    Robot* robot2 = new Robot("Robot2", 20, 2, 1, new FighterStrategy(), new FinisherStrategy(), new GreedyStrategy());
    Robot* robot3 = new Robot("Robot3", 12, 4, 2, new ExplorerStrategy(), new FinisherStrategy(), new GreedyStrategy());
    Robot* robot4 = new Robot("Robot4", 19, 2, 2, new FighterStrategy(), new FinisherStrategy(), new IgnorerStrategy());
    Robot* robot5 = new Robot("Robot5", 100, 2, 3, new FighterStrategy(), new TankKillerStrategy(), new IgnorerStrategy());

    location1->addRobot(robot1);
    location1->addRobot(robot2);
    location2->addRobot(robot3);
    location2->addRobot(robot4);
    location3->addRobot(robot5);

    Resource* resource1 = new Resource(5);
    Resource* resource2 = new Resource(10);

    location3->addResource(resource1);
    location3->addResource(resource2);

    Simulation* simulation = new Simulation();

    Enviroment* enviroment = simulation->getEnviroment();

    enviroment->addLocation(location1);
    enviroment->addLocation(location2);
    enviroment->addLocation(location3);

    enviroment->connectLocations(location1, location3);
    enviroment->connectLocations(location3, location2);

    enviroment->addRobot(robot1);
    enviroment->addRobot(robot2);
    enviroment->addRobot(robot3);
    enviroment->addRobot(robot4);
    enviroment->addRobot(robot5);

    int maxSteps = 50;
    while (maxSteps && !simulation->isFinished()) {
        simulation->performStage();
        maxSteps--;
    }

    return 0;
}