/*
  ==============================================================================

    meter.h
    Created: 15 Feb 2015 4:08:19pm
    Author:  Milan

  ==============================================================================
*/

#ifndef METER_H_INCLUDED
#define METER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class meter    : public Component
{
public:
    meter();
    ~meter();

    void paint (Graphics&);
    void resized();

	void update(float newpeak, float newrms);

private:
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(meter)
		float rms;
	float peak;
};


#endif  // METER_H_INCLUDED
