/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <iostream>
#include "windows.h"

#include <string>
using namespace std;


//==============================================================================
MainContentComponent::MainContentComponent()
{
    setSize (500, 400);
	startAudioCallback();

}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xffeeddff));

    g.setFont (Font (16.0f));
    g.setColour (Colours::black);
    g.drawText ("Delaytime: " + to_string(delaytime) + ", Distortion: " + to_string(distortionamount), getLocalBounds(), Justification::centred, true);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::mouseDrag(const MouseEvent& event)
{
	delaytime = min(buffersize, max(event.x, 1));

	distortionamount = pow(((float)event.y / getHeight()), 2);

	repaint();
}


void MainContentComponent::audioCallback(float** buffer, int channels, int frames)
{
	buffersize = frames;

	amp(buffer[1], 1, frames);
	Delay(buffer[1], delaytime, 0.9, frames);
	distort(buffer[1], distortionamount, frames);
	amp(buffer[1], 2 / distortionamount, frames);

	for (size_t i = 0; i < frames; i++)
	{
		if (buffer[0][i] > 1)
		{
			buffer[0][i] = 1;
		}
		if (buffer[0][i] < -1)
		{
			buffer[0][i] = -1;
		}

		buffer[0][i] = buffer[1][i];
	}

	buffer[1] = buffer[1];



}