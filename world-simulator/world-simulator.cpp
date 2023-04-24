#include <iostream>
#include "World.h"
#include "Wolf.h"

int main()
{
    World* world = World::GetInstance();
    world->Initialize(20, 20);

    world->Simulate();
}