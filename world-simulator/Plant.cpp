#include "Plant.h"
#include "World.h"

const float PLANT_PROBABILITY_TO_SPREAD = 0.1;
Plant::Plant() {
	initiative = 0;
}

Plant::Plant(Point2D& initialPosition):Organism(initialPosition) {
	initiative = 0;

	visual = 'P';
}

bool Plant::Defend(Organism* attacker) {
	return Organism::Defend(attacker);
}
// Returns position to which Plant should spread
// or nullptr if won't spread
Point2D* Plant::GetSpreadPosition() {
	World* world = World::GetInstance();

	float random = randomNumber();

	if (random > PLANT_PROBABILITY_TO_SPREAD) {
		return nullptr;
	}

	vector<Point2D>* neighbouringFields = world->GetNeighbouringFields(*position);
	int length = neighbouringFields->size();

	int index = randomInteger(0, length - 1);
	Point2D* positionToSpread = new Point2D((*neighbouringFields)[index]);

	delete neighbouringFields;

	return positionToSpread;
}

void Plant::Spread() {
	Point2D* spreadPosition = GetSpreadPosition();
	if (spreadPosition != nullptr) {
		World* world = World::GetInstance();

		Plant* newPlant = new Plant();
		newPlant->SetPosition(*spreadPosition);
		world->GetOrganisms()->push_back(newPlant);
	}
}

void Plant::Action() {
	Spread();
}

