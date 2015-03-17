/*
  ==============================================================================

    onset.h
    Created: 17 Feb 2015 9:51:03pm
    Author:  Milan

  ==============================================================================
*/

#ifndef ONSET_H_INCLUDED
#define ONSET_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class onsetdetection
{
public:
	void peeks(AudioSampleBuffer* in, AudioSampleBuffer* out, AudioSampleBuffer* vorige); //extract peeks from an audiosignal. Samples that are not a peek will be 0.
	void rms(AudioSampleBuffer* in, AudioSampleBuffer* out, AudioSampleBuffer* vorige, int numsamples); //calculate the rms values over a time of numsamples

	void differentiate(AudioSampleBuffer* in, AudioSampleBuffer* out, AudioSampleBuffer* vorige); //differentiate an audio signal
	void difftomidi(AudioSampleBuffer* diffin, AudioSampleBuffer* audioin, MidiBuffer* midiout, int pitch, float velocity, float treshold, float offtreshold, int* counter, int max1per, float keyscaling); //triggers midi note on messages from a (twice) differentiated audio signal

private:
	int buffersize;
	int diff_aantalnullen = 0;
	float diff_vorige = 0;
	AudioSampleBuffer vorige;
	float laatstesample = 0;
	BigInteger j = 0;
	BigInteger vorigej = 0;
	bool noteon = false;
};



#endif  // ONSET_H_INCLUDED
