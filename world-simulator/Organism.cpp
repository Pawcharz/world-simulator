#include "Organism.h"

Organism::Organism() {
	position = new Point2D(0, 0);

	visual = 'O';
}

void Organism::SetPosition(Point2D& newPosition) {
	*position = newPosition;
}

Point2D& Organism::GetPosition() {
	return *position;
}

char Organism::GetVisual() {
	return visual;
}