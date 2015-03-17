/*
  ==============================================================================

  onset.cpp
  Created: 17 Feb 2015 9:51:03pm
  Author:  Milan

  ==============================================================================
  */

#include "onset.h"

void onsetdetection::peeks(AudioSampleBuffer* in, AudioSampleBuffer* out, AudioSampleBuffer* vorige) //extract peeks from an audiosignal. Samples that are not a peek will be 0.
{
	buffersize = in->getNumSamples();
	
	for (size_t i = 0; i < buffersize; i++)
	{

		if (i == 0)
		{
			if ((abs(vorige->getSample(0, buffersize - 1)) < abs(in->getSample(0, i))) && (abs(in->getSample(0, i + 1)) < abs(in->getSample(0, i))))
			{
				out->setSample(0, i, abs(in->getSample(0, i)));
			}
			else
			{
				out->setSample(0, i, 0);
			}

		}
		else if (i == buffersize - 1)
		{
			out->setSample(0, i, 0);
		}
		else
		{


			if ((abs(in->getSample(0, i - 1)) < abs(in->getSample(0, i))) && (abs(in->getSample(0, i + 1)) < abs(in->getSample(0, i))))
			{
				out->setSample(0, i, abs(in->getSample(0, i)));
			}
			else
			{
				out->setSample(0, i, 0);
			}

		}


	}
}

void onsetdetection::rms(AudioSampleBuffer* in, AudioSampleBuffer* out, AudioSampleBuffer* vorige, int numsamples) //calculates rms with time numsamples
{
	buffersize = in->getNumSamples();

	for (size_t i = 0; i < buffersize; i++)
	{
		if (i > numsamples)
		{
			out->setSample(0, i, in->getRMSLevel(0, i - numsamples, numsamples));
		}
		else
		{
			out->setSample(0, i, in->getRMSLevel(0, 0, numsamples));
		}
	}

}


void onsetdetection::differentiate(AudioSampleBuffer* in, AudioSampleBuffer* out, AudioSampleBuffer* vorige) //differentiate an audio signal, interpolating between peeks at samples with a value of 0
{
	buffersize = in->getNumSamples();
	float dx = 0, dy = 0, dydx = 0;
	int laatstepeak = 0;

	for (size_t i = 0; i < buffersize; i++)
	{
		if (in->getSample(0, i) == 0) 
		{
			diff_aantalnullen += 1; //sample is 0
		}
		else
		{
			dx = diff_aantalnullen + 1;
			dy = in->getSample(0, i) - diff_vorige;

			dydx = (float)dy / dx;

			for (size_t countout = i - dx; countout <= i; countout++)
			{
				if (countout >= 0)
				{
					out->setSample(0, countout, dydx);
				}


			}

			diff_aantalnullen = 0;
			diff_vorige = in->getSample(0, i);
			laatstepeak = i;
		}


	}

	for (size_t j = laatstepeak; j < buffersize; j++)
	{
		out->setSample(0, j, dydx);
	}
}

void onsetdetection::difftomidi(AudioSampleBuffer* diffin, AudioSampleBuffer* audioin, MidiBuffer* midiout, int pitch, float velocity, float treshold, float offtreshold, int* counter, int max1per, float keyscaling)
{
	treshold = treshold * (1 + (keyscaling * ((pitch - 60) * ((float)1 / 60)))); //keyscaling: lagere noten krijgen een lagere treshold dan hogere noten, omdat ze door de lagere frequentie automatisch een langzamere attack hebben (ofzo...)

	offtreshold = offtreshold * (1 + (keyscaling * ((pitch - 60) * ((float)1 / 60)))); //keyscaling

	float vorige = 0, volgende = 0;
	for (size_t i = 0; i < buffersize; i++)
	{
		if (noteon && audioin->getRMSLevel(0, 0, buffersize) < offtreshold)
		{
			midiout->addEvent(MidiMessage::noteOff(1, pitch), 1);
			noteon = false;
		}

		if (i > 0 && i < buffersize - 1)
		{
			vorige = diffin->getSample(0, i - 1);
			volgende = diffin->getSample(0, i + 1);
		}
		else if (i == 0)
		{
			volgende = diffin->getSample(0, i + 1);
			vorige = laatstesample;
		}




		if (diffin->getSample(0, i) > treshold && diffin->getSample(0, i) > vorige && diffin->getSample(0,i) > volgende) //sample is groter dan omliggende samples: piek in acceleratie
		{
			if (j > vorigej + max1per) //om te zorgen dat er niet 100 noten heel kort achter elkaar getriggerd worden. (zou in theorie niet nodig moeten zijn, maar blijkt heel hard nodig te zijn...
			{
				if (noteon == true)
				{
					midiout->addEvent(MidiMessage::noteOff(1, pitch), 1);
					noteon = false;
				}


				midiout->addEvent(MidiMessage::noteOn(1, pitch, (float)1), 1);
				noteon = true;
				*counter += 1;
			}

			vorigej = j;
		}
	}
	laatstesample = diffin->getSample(0, buffersize);
	j++;



}
