/*
  ==============================================================================

    audio2midi.h
    Created: 9 Mar 2015 7:27:08pm
    Author:  Milan

  ==============================================================================
*/

#ifndef AUDIO2MIDI_H_INCLUDED
#define AUDIO2MIDI_H_INCLUDED

#include "onset.h"
#include "bandpassfilter.h"



class audio2midi : onsetdetection, bandpassfilter
{
public:
	audio2midi();
	~audio2midi();

	void setup(int note);
	void execute(AudioSampleBuffer* in, MidiBuffer* out, int SR, float treshold, float offtreshold, int* nummessagessent, int mindt, float keyscaling);

private:
	int note;
	AudioSampleBuffer peeks, rmsbuf, diff1, diff2, incopy, vorige;
	int buffersize = 480;

};




#endif  // AUDIO2MIDI_H_INCLUDED
