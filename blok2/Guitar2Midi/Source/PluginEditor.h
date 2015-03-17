/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_7D7FB94EE9C781C4__
#define __JUCE_HEADER_7D7FB94EE9C781C4__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "meter.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Guitar2midiAudioProcessorEditor  : public AudioProcessorEditor,
                                         public Timer,
                                         public ButtonListener,
                                         public SliderListener
{
public:
    //==============================================================================
    Guitar2midiAudioProcessorEditor (Guitar2midiAudioProcessor& ownerFilter);
    ~Guitar2midiAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

	void timerCallback();
	Guitar2midiAudioProcessor* getProcessor() const
	{
		return static_cast <Guitar2midiAudioProcessor*>(getAudioProcessor());
	}

	void meterinupdate(float peak, float rms);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> textButton;
    ScopedPointer<meter> inmeter;
    ScopedPointer<Label> label;
    ScopedPointer<Slider> slider;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;
    ScopedPointer<Slider> offslider;
    ScopedPointer<Label> label5;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> deltat;
    ScopedPointer<Label> label7;
    ScopedPointer<Slider> keysc;
    ScopedPointer<Label> keyscaling;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Guitar2midiAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7D7FB94EE9C781C4__
