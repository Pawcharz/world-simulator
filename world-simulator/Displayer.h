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


	//static Displayer* displayerInstance;

public:

	//static Displayer* GetInstance();

	Displayer();

	~Displayer();

	void DrawWorld();

	void AddLog(string logText);
};

