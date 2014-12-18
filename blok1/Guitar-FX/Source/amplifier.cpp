/*
  ==============================================================================

    amplifier.cpp
    Created: 10 Dec 2014 3:01:35pm
    Author:  Milan

  ==============================================================================
*/

#include "amplifier.h"


Amplifier::Amplifier()
{
}

Amplifier::~Amplifier()
{
}

void Amplifier::amp(float* buffer, float level, float frames)
{
	for (size_t i = 0; i < frames; i++)
	{
		buffer[i] = buffer[i] * level;
	}
}
