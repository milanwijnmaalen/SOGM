/*
  ==============================================================================

    audio2midi.cpp
    Created: 9 Mar 2015 7:27:08pm
    Author:  Milan

  ==============================================================================
*/

#include "audio2midi.h"

audio2midi::audio2midi()
{
}

audio2midi::~audio2midi()
{
}

void audio2midi::setup(int newnote)
{
	note = newnote;
}

void audio2midi::execute(AudioSampleBuffer* in, MidiBuffer* out, int SR, float threshold, float offtreshold, int* nummessagessent, int mindt, float keyscaling)
{
	buffersize = in->getNumSamples();

	incopy = *in;
	//peeks = *in;
	//rmsbuf = *in;
	//diff1 = *in;
	//diff2 = *in;

	peeks.setSize(1, buffersize, false, true, false);
	rmsbuf.setSize(1, buffersize, false, true, false);
	diff1.setSize(1, buffersize, false, true, false);
	diff2.setSize(1, buffersize, false, true, false);

	peeks.clear();
	rmsbuf.clear();
	diff1.clear();
	diff2.clear();

	bandpassfilter::setup(4, SR, note);

	bandpassfilter::process(buffersize, incopy.getArrayOfChannels());

	incopy.applyGain(2);

	if (vorige.getNumSamples() == buffersize)
	{

		//onset.peeks(&buffer, &peeks, &vorige);
		rms(&incopy, &rmsbuf, &vorige, 10);
		differentiate(&rmsbuf, &diff1, &vorige);
		differentiate(&diff1, &diff2, &vorige);
		difftomidi(&diff2, &incopy, out, note, 1 , threshold, offtreshold, nummessagessent, mindt, keyscaling);
	}


	vorige = incopy;
}