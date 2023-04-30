#include "utlis.h"

#include "Point2D.h"
#include "World.h"

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


char* parseIntToChar(int inputValue) {
	char* buffer = new char[16]();
	int newValue = inputValue;

	int i = 0;
	do
	{
		int lastPart = newValue % 10;
		newValue -= lastPart;
		newValue /= 10;

		buffer[i] = lastPart + '0';

		i++;
	} while (newValue != 0);
	buffer[i] = '\0';

	int size = i;

	char* reversed = new char[16]();
	int j = 0;
	for (i = size - 1; i >= 0; i--, j++)
	{
		reversed[j] = buffer[i];
	}
	reversed[size] = '\0';

	return reversed;
}