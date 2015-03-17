/*
  ==============================================================================

    filter.cpp
    Created: 21 Feb 2015 1:30:10pm
    Author:  Milan

  ==============================================================================
*/

#include "bandpassfilter.h"
#include "DspFilters\ChebyshevI.h"


bandpassfilter::bandpassfilter()
{
}

void bandpassfilter::setup(int neworder, int newSR, int midi)
{
	order = neworder;
	SR = newSR;
	freq = mtof(midi);
	ripple = 0.01;
	
	f.setup(order, SR, freq, width, ripple);



}


bandpassfilter::~bandpassfilter()
{
}

void bandpassfilter::process(int numsamples, float* samples[])
{
	f.process(numsamples, samples);
}

float bandpassfilter::mtof(int midi)
{
	//float eentwaalfde = (float)1 / 12;
	//width = (8.175799 * pow(pow(2, eentwaalfde), midi)) - (8.175799 * pow(pow(2, eentwaalfde), midi - 1));

	//return 8.175799 * pow(pow(2, eentwaalfde), midi);

	float freq = 440 * pow(2, (float) (midi - 69) / 12);

		width = freq - (440 * pow(2, (float)(midi - 1 - 69) / 12));

	return freq;

}