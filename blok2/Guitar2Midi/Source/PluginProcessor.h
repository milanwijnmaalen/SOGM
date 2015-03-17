/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "onset.h"
#include "bandpassfilter.h"
#include "audio2midi.h"

//==============================================================================
/**
*/
class Guitar2midiAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Guitar2midiAudioProcessor();
    ~Guitar2midiAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    int getNumParameters() override;
    float getParameter (int index) override;
    void setParameter (int index, float newValue) override;

    const String getParameterName (int index) override;
    const String getParameterText (int index) override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	float rms;
	float peak;

	float aantalnullen = 0;
	float aantalpieken = 0;

	float aantalpositief = 0;
	float aantalnegatief = 0;

	float threshold = 0.005;
	
	int mindt = 1;
	float keysc = 0;

	float buffersize;
	int nummessagessent = 0;

	float offtreshold;

	onsetdetection onset;
	AudioSampleBuffer vorige;

	AudioSampleBuffer peeks;
	AudioSampleBuffer diff1;
	AudioSampleBuffer diff2;
	AudioSampleBuffer rmsbuf;

	bandpassfilter filter;

	audio2midi tomidi[24];

private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Guitar2midiAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
