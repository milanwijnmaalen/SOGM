/*
  ==============================================================================

    amplifier.h
    Created: 10 Dec 2014 3:01:35pm
    Author:  Milan

  ==============================================================================
*/

#ifndef AMPLIFIER_H_INCLUDED
#define AMPLIFIER_H_INCLUDED

class Amplifier
{
public:
	Amplifier();
	~Amplifier();

	void amp(float* buffer, float level, float frames);

private:

};




#endif  // AMPLIFIER_H_INCLUDED
