#include <iostream>
#include "World.h"
#include "Wolf.h"
#include "Displayer.h"


int main()
{
    World* world = World::GetInstance();
    world->Initialize(3, 3);

    Displayer* displayer = Displayer::GetInstance();
    displayer->DrawWorld();

    world->Simulate();
}