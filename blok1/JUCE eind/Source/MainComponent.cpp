#include "MainComponent.h"
#include <iostream>
#include "windows.h"
#include <string>
#include "bal.h"
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

bool flipLR = false;

//==============================================================================
MainContentComponent::MainContentComponent()
{
	bal touchpoint[10];
    setSize (1280, 600);
	x = 0;
	y = 0;
	startTimer(16);
	context.setRenderer(this);

	context.attachTo(*this);

	File eagle = "C:/Users/Milan/Documents/ownCloud/HKU/SOGM/JUCE 1/Source/eagle.png";
	img = ImageFileFormat::loadFrom(eagle);


	startAudioCallback();
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
	ColourGradient gradient(Colours::beige, 0, getHeight() / 2, Colours::aqua, 1280, getHeight() / 2, true);
	//ColourGradient gradient(Colours::beige, 0, getHeight() / 2, Colours::aqua, 1280, getHeight() / 2, true);
	//ColourGradient gradient(Colour::fromRGBA(50, 50, 50, 50), getWidth() / 2, getHeight() / 2, Colours::aqua, 0, 0, true);
	Colour kleuren[] = { Colours::red, Colours::azure, Colours::olive, Colours::khaki, Colours::hotpink, Colours::mistyrose, Colours::cyan, Colours::indianred, Colours::mediumspringgreen, Colours::gold };

	for (int tel3 = 0; tel3 < 10; tel3++)
	{
		if (touchpoint[tel3].getvisible() == true){
			float at = touchpoint[tel3].getX() / getWidth();
			if (at < 0)
			{
				at = 0;
			}
			else if (at > 1)
			{
				at = 1;
			}
			//touchpoint[tel3].setfreq(200 + getHeight() - touchpoint[tel3].getY());
			//touchpoint[tel3].setpan(touchpoint[tel3].getX() / getWidth());
			gradient.addColour(at, kleuren[tel3]);
		}

	}

	unsigned int thisframetime = GetTickCount();

	if ((thisframetime - lastframetime) > 0){
		fps = 1000 / (thisframetime - lastframetime);
	}
	else{
		fps = 9999;
		OutputDebugString("2 Frames tegelijk?");
	}


	gradient.multiplyOpacity(0.2);

	g.setGradientFill(gradient);
    g.fillAll ();

	

	g.drawImageAt(img, getWidth() / 2 - img.getWidth() / 2, getHeight() / 2 - img.getHeight() / 2);

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
	g.fillRect(getWidth() - 100, getHeight() - 20, 100, 20);
	g.setColour(Colours::black);

	g.drawText("freq: " + to_string((int)touchpoint[0].getfreq()) + " " + to_string(fps) + " fps", getLocalBounds(), Justification::bottomRight, true);
	
	for (float note = 0; note < 50; note++)
	{
		float x = 196 * powf(2, note / 12);
		
		if ((int)note % 12 == 0){
			g.drawHorizontalLine(200 + getHeight() - x, 0, 20);
		}


		g.drawHorizontalLine(200 + getHeight() - x, 0, 10);
	}

	for (size_t i = 0; i < 10; i++)
	{
		if (touchpoint[i].getvisible()){
			g.drawEllipse(touchpoint[i].getX() - 50, touchpoint[i].getY() - 50, 100, 100, 1);
		}
	}
	lastframetime = thisframetime;
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}

void MainContentComponent::mouseDrag(const MouseEvent& event)
{
	muisnr = event.source.getIndex();
	touchpoint[muisnr].setX(event.x);
	touchpoint[muisnr].setY(event.y);
	
	touchpoint[muisnr].setfreq(200 + getHeight() - touchpoint[muisnr].getY());
	touchpoint[muisnr].setpan(touchpoint[muisnr].getX() / getWidth());


}

void MainContentComponent::mouseDown(const MouseEvent& event)
{
	muisnr = event.source.getIndex();

	touchpoint[muisnr].setX(event.x);
	touchpoint[muisnr].setY(event.y);

	touchpoint[muisnr].setfreq(200 + getHeight() - touchpoint[muisnr].getY());
	touchpoint[muisnr].setpan(touchpoint[muisnr].getX() / getWidth());

	touchpoint[muisnr].setvisible(true);
	touchpoint[muisnr].activate(true);


	float proportion = 0.5;
}

void MainContentComponent::mouseUp(const MouseEvent& event)
{
	muisnr = event.source.getIndex();
	touchpoint[muisnr].setvisible(false);
	touchpoint[muisnr].activate(false);
	
}

void MainContentComponent::timerCallback()
{
	repaint();
}


void MainContentComponent::newOpenGLContextCreated() { }

void MainContentComponent::renderOpenGL() { }

void MainContentComponent::openGLContextClosing() { }

void MainContentComponent::audioCallback(float** buffer, int channels, int frames)
{
	//i = touchpoint[0].calculatesine(i, buffers[0], frames, SR);

	for (size_t tel5 = 0; tel5 < frames; tel5++)
	{
		for (size_t tel6 = 0; tel6 < channels; tel6++)
		{
			buffer[tel6][tel5] = 0;
		}
	}


	for (size_t tel4 = 0; tel4 < 10; tel4++)
	{
		touchpoint[tel4].calculatesine(buffers[tel4], frames, SR, 10000,20,1,30);

		for (size_t teller2 = 0; teller2 < frames; teller2++)
		{
			for (size_t channel = 0; channel < channels; channel++)
			{
				float A = 0.5;
				if (channel == 0)
				{
					A = 1 - touchpoint[tel4].getpan();
				}
				else if (channel == 1)
				{
					A = touchpoint[tel4].getpan();
				}
				if (flipLR == true)
				{
					A = 1 - A;
				}


				buffer[channel][teller2] = buffer[channel][teller2] + A * buffers[tel4][teller2];
			}
		}
	}

	for (size_t tel7 = 0; tel7 < frames; tel7++)
	{
		for (size_t tel8 = 0; tel8 < channels; tel8++)
		{
			//buffer[tel8][tel7] = buffer[tel8][tel7] * 0.2;
		}
	}


}