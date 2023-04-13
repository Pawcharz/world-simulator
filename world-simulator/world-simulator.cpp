#include <iostream>
#include "World.h"
#include "Wolf.h"
#include "Displayer.h"


int main()
{
    World* world = World::GetInstance();
    world->Initialize(20, 20);

    Displayer* displayer = new Displayer();
    displayer->DrawWorld();
}