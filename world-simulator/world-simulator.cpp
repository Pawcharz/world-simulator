#include <iostream>
#include "World.h"

int main()
{
    World* world = World::GetInstance();
    world->Initialize(20, 20);

    world->Simulate();
}