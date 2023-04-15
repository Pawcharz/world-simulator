#pragma once
#include <cstdlib>
#include <vector>


const int INVALID_INDEX = -1;

template<typename T>
void customSwap(T** pointerA, T** pointerB) {

	T* temp = *pointerA;
	*pointerA = *pointerB;
	*pointerB = temp;
}



float randomNumber();

int randomInteger(int min, int max);

int roundToInt(float number);