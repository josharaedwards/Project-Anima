#pragma once

class Dodecaphonic
{
protected:
	int series[12];

	int ToMod12(int note);

public:
	// constructors
	Dodecaphonic();
	Dodecaphonic(int* notes);

	// note methods
	int GetNote(int index);
	void SetNote(int note, int index);

	// basic operations
	Dodecaphonic Transpose(int interval);
	Dodecaphonic Invert();
	Dodecaphonic Retrograde();
};

