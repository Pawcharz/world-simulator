#include "utlis.h"

float randomNumber() {
	int base = rand();
	float result = (float)base / (float)RAND_MAX;

	return result;
}

int randomInteger(int min, int max) {
	int difference = max - min;
	float base = randomNumber();
	base *= difference;

	return base + min;
}


int roundToInt(float number) {
	int base = number;

	if (number - base >= 0.5) {
		return base + 1;
	}

	return base;
}