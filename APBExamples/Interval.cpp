#include "Interval.h"

void Interval::PromptCalcInterval()
{
    ToConsole speaker;
    interval = 0;
 
    speaker.SayHello();
    printf("Please enter two natural notes. \nFirst Node: ");

    if (scanf_s("%c%c", &note1, 1, &temp, 1) <= 0)
    {
        speaker.Print("Error: Bad Scan");
        return;
    }

    printf("Second Note: ");

    if (scanf_s("%c", &note2, 1) <= 0)
    {
        speaker.Print("Error: Bad Scan");
        return;
    }

    //Calculate the interval
    interval = NameToPc(note2) - NameToPc(note1);

    if (interval > 20 || interval < -11)
    {
        printf("Either %c or %c are invalid notes.\n", note1, note2);
        return;
    }

    if (interval < 0)
    {
        interval += 12;
    }
    else if (interval > 11)
    {
        interval -= 12;
    }

    printf("There are either %d semitones up or %d semitones down.\n", interval, interval ? 12 - interval : 0);
}

int Interval::NameToPc(char name)
{
    switch (name)
    {
    case 'C':
    case 'c':
        return 0;
    case 'D':
    case 'd':
        return 2;
    case 'E':
    case 'e':
        return 4;
    case 'F':
    case 'f':
        return 5;
    case 'G':
    case 'g':
        return 7;
    case 'A':
    case 'a':
        return 9;
    case 'B':
    case 'b':
        return 11;
    //Error prompt
    default:
        return 100;
    }
}
