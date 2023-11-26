#pragma once
#include <stdio.h>
#include <stdlib.h>

class Interval
{
	char note1, note2, temp;
	int interval;

	int NameToPc(char name);

public:
	int CalcInterval(int note1, int note2);
};

