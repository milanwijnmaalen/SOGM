/*
  ==============================================================================

    filter.h
    Created: 21 Feb 2015 1:30:10pm
    Author:  Milan

  ==============================================================================
*/

#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include "DspFilters\ChebyshevI.h"

class bandpassfilter
{
public:
	bandpassfilter();
	~bandpassfilter();
	void process(int numsamples, float* samples[]);
	void setup(int neworder, int newSR, int midi);
	float mtof(int midi); //calculates the frequency of a midi note, and sets with to the distance to the next note

private:
	Dsp::SimpleFilter <Dsp::ChebyshevI::BandPass <4>, 1> f;
	int order = 4;
	int SR;
	float freq;
	float width;
	float ripple = 0.001;

};




#endif  // FILTER_H_INCLUDED
