#pragma once

#include "utlis.h"
#include "Wolf.h"
#include "Sheep.h"

#include <vector>
#include <iostream>

using namespace std;


class Displayer
{
private:
	vector<vector<char*>*>* screenBuffer;

	vector<string>* logs;


	void ResetLogs();

	void UpdateBuffer();


public:

	Displayer();

	//~Displayer();

	void DrawWorld();

	void AddLog(string logText);
};

