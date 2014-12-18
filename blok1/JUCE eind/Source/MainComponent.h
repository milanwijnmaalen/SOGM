/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/
#pragma once
#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "bal.h"
#include "AudioCallback.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainContentComponent   : public Component, public Timer, public OpenGLRenderer, private AudioCallback
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();

    void paint (Graphics&);
    void resized();
	void mouseDrag(const MouseEvent& event);
	void mouseUp(const MouseEvent& event);
	void mouseDown(const MouseEvent& event);
	void newOpenGLContextCreated();
	void renderOpenGL();
	void openGLContextClosing();
	OpenGLContext context;

private:
	int x;
	int y;
	int muisnr;
	bal touchpoint[10];
	ColourGradient gradient;
	Image img;
	void timerCallback();
	unsigned int lastframetime;
	float fps;
	void audioCallback(float** buffer, int channels, int frames);
	float buffers[10][10000];

	int SR = 44100;
	float f = 500;
	float newf = 500;


	float P = SR / f;
	float halfP = P / 2;

	int dur = 1024;
	float A = 0.1;
	int i = 0;

	float buffer0[10000];


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
