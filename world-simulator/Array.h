#pragma once
#include "utlis.h"
#include <stdexcept>

#include <iostream>

using namespace std;

template<typename T>
class vector
{
private:
	T* data;
	int length;

public:

	vector() {
		length = 0;
		data = nullptr;
	}

	vector(int initLength) {
		length = initLength;
		data = new T[initLength];
	}

	vector(const T* initData, int initLength) {
		length = initLength;
		data = new T[initLength];

		for (int i = 0; i < initLength; i++) {
			data[i] = initData[i];
		}
	}

	vector<T>& operator=(vector<T>& other) {
		vector<T>& tmp = other;

		customSwap(&data, &tmp.data);
		length = tmp.length;

		return *this;
	}


	void Add(T& element) {
		int newLength = length + 1;
		T* tmp = new T[newLength];

		for (int i = 0; i < length; i++)
		{
			tmp[i] = data[i];
		}
		tmp[length] = element;
		delete[] data;

		customSwap(&data, &tmp);
		length = newLength;
	}

	void Add(T* element) {
		int newLength = length + 1;
		T* tmp = new T[newLength];

		for (int i = 0; i < length; i++)
		{
			tmp[i] = data[i];
		}
		tmp[length] = *element;
		delete[] data;

		customSwap(&data, &tmp);
		length = newLength;
	}

	int GetIndex(T* element) {
		for (int i = 0; i < length; i++) {

			if (&data[i] == element) {
				return i;
			}
		}

		return INVALID_INDEX;
	}

	void RemoveSpecific(int index) {

		int newLength = length - 1;

		T* newData = new T[newLength];

		for (int i = 0; i < index; i++) {
			newData[i] = data[i];
		}
		for (int i = index + 1; i < newLength; i++) {
			newData[i] = data[i];
		}

		delete[] data;
		customSwap(&newData, &data);
	}

	int GetLength() {
		return length;
	}


	// Whyn not working?
	//T& operator[](const int i);

	T& GetElement(int index) {
		return data[index];
	}

	T* GetElementPtr(int index) {
		return &data[index];
	}
};
