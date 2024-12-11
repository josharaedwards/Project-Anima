#include "ToConsole.h"

void ToConsole::Print(string message)
{
    cout << message;
}

void ToConsole::SayHello()
{
	cout << "Hello Earthlings!\n\n";
}

void ToConsole::PromptInterval()
{
    Interval intervalObj;
    char note1, note2, temp;

    SayHello();
    printf("Please enter two natural notes. \nFirst Note: ");

    if (scanf_s("%c%c", &note1, 1, &temp, 1) <= 0)
    {
        Print("Error: Bad Scan");
        return;
    }

    printf("Second Note: ");

    if (scanf_s("%c", &note2, 1) <= 0)
    {
        Print("Error: Bad Scan");
        return;
    }

    intervalObj.CalcInterval(note1, note2);

	printf("\n\n");
}

int ToConsole::PromptDodecaphonic(int argc, char** argv)
{
    Dodecaphonic row, res;
    int interval, n;

    if (argc != 14 || argv[1][0] != '-')
    {
        printf("Usage: %s [-oN | -rN | -iN | -irN ]" "note1 note2 ... note12]\n", argv[0]);

        return -1;
    }

    // initialize the row object
    for (n = 0; n < 12; ++n)
    {
        row.SetNote(atoi(argv[n + 2]), n);
    }

	switch (argv[1][1])
	{
	// original transposed
	case 'o':
		interval = atoi(argv[1] + 2);
		res = row.Transpose(interval);
		break;
	// retrograde
	case 'r':
		interval = atoi(argv[1] + 2);
		res = row.Retrograde().Transpose(interval);
		break;
	//inverted
	case 'i':
		if (argv[1][3] != 'r')
		{
			interval = atoi(argv[1] + 2);
			res = row.Invert().Transpose(interval);
		}
	//inverted retrograde
		else
		{
			interval = atoi(argv[1] + 3);
			res = row.Invert().Retrograde().Transpose(interval);
		}
		break;
	default:
		printf("unrecognized option \n");
		return -1;
	}

	for (int m = 0; m < 12; ++m)
	{
		printf("%d ", res.GetNote(m));
	}

	printf("\n");

	return 0;
}
