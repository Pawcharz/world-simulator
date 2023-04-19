#pragma once
#include "Plant.h"

class SosnowskysHogweed : public Plant
{
	DEFENCE_RESULT Defend(Organism* attacker);

public:
	SosnowskysHogweed();

	~SosnowskysHogweed();

	void Action();
};

