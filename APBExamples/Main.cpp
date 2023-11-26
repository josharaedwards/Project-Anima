#include "ToConsole.h"

int main(int argc, char** argv)
{
	ToConsole speaker;

	//Calculates the interval between natural notes
	speaker.PromptInterval();

	//Calculates the transform operation of a dodecaphonic based on console arguments
	speaker.PromptDodecaphonic(argc, argv);

	return 0;
}