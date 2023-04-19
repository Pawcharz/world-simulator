#include <iostream>
#include "World.h"
#include "Wolf.h"

int main()
{
    World* world = World::GetInstance();
    world->Initialize(10, 10);

    world->Simulate();
}