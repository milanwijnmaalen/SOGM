/*
  ==============================================================================

    meter.cpp
    Created: 15 Feb 2015 4:08:19pm
    Author:  Milan

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "meter.h"

//==============================================================================
meter::meter()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

meter::~meter()
{
}

void meter::paint (Graphics& g)
{
    g.fillAll (Colours::green);   // clear the background

	float hoogterms = rms * getHeight();
	float hoogtepeak = peak * getHeight();
	g.setColour(Colours::blue);
	g.fillRect((float)0, (float)getHeight() - hoogtepeak, (float)getWidth(), (float)hoogtepeak);
	g.setColour(Colours::blueviolet);
	g.fillRect((float)0, (float)getHeight() - hoogterms, (float)getWidth(), (float)hoogterms);
}

void meter::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void meter::update(float newpeak, float newrms)
{
	rms = newrms;

	if (newpeak < peak && peak - 0.03 > newpeak)
	{
		peak -= 0.03;
	}
	else
	{
		peak = newpeak;
	}

	repaint();
}