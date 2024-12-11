#include "Dodecaphonic.h"

Dodecaphonic::Dodecaphonic()
{
    for (int i = 0; i < 12; ++i)
    {
        series[i] = 0;
    }
}

Dodecaphonic::Dodecaphonic(int* notes)
{
    for (int i = 0; i < 12; ++i)
    {
        series[i] = ToMod12(notes[i]);
    }
}

int Dodecaphonic::ToMod12(int note)
{
    while (note >= 12)
    {
        note -= 12;
    }

    while (note < 0)
    {
        note += 12;
    }

    return note;
}

int Dodecaphonic::GetNote(int index)
{
    return series[ToMod12(index)];
}

void Dodecaphonic::SetNote(int note, int index)
{
    series[ToMod12(index)] = ToMod12(note);
}

// Moves a phrase up or down an interval
Dodecaphonic Dodecaphonic::Transpose(int interval)
{
    Dodecaphonic transp;

    for (int i = 0; i < 12; ++i)
    {
        int transpNote = ToMod12(series[i] + interval);

        transp.SetNote(transpNote, i);
    }

    return transp;
}

// Transform a phrase upside-down
Dodecaphonic Dodecaphonic::Invert()
{
    Dodecaphonic inv;

    inv.SetNote(series[0], 0);

    for (int i = 1; i < 12; ++i)
    {
        int invNote = ToMod12(inv.GetNote(i - 1) + series[i - 1]);

        inv.SetNote(invNote, i);
    }

    return inv;
}

// Transform a phrase to reverse order
Dodecaphonic Dodecaphonic::Retrograde()
{
    Dodecaphonic retr;

    for (int i = 0; i < 12; ++i)
    {
        retr.SetNote(series[i], 11 - i);
    }

    return retr;
}
