#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Interval.h"
#include "Dodecaphonic.h"

using namespace std;

class ToConsole
{
	void Print(string message);

public:
	void SayHello();
	void PromptInterval();
	int PromptDodecaphonic(int argc, char** argv);
};

