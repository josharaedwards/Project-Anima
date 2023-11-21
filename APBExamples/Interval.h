#pragma once
#include "ToConsole.h"

class Interval
{
	char note1, note2, temp;
	int interval;

	int NameToPc(char name);

public:
	void PromptCalcInterval();
};

