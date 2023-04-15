#include <iostream>
#include "World.h"
#include "Wolf.h"
#include "Displayer.h"


int main()
{
    World* world = World::GetInstance();
    world->Initialize(5, 5);

    Displayer* displayer = Displayer::GetInstance();
    displayer->DrawWorld();

    world->Simulate();
}