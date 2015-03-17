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

//[Headers] You can add your own extra header files here...
#include "meter.h"
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Guitar2midiAudioProcessorEditor::Guitar2midiAudioProcessorEditor (Guitar2midiAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    addAndMakeVisible (textButton = new TextButton ("new button"));
    textButton->setButtonText (TRANS("Reset"));
    textButton->addListener (this);

    addAndMakeVisible (inmeter = new meter());
    inmeter->setName ("Audio in meter");

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("label text")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0.0001, 1, 0);
    slider->setSliderStyle (Slider::LinearVertical);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("label text")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("label text")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("label text")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (offslider = new Slider ("noteoff treshold"));
    offslider->setRange (1e-006, 1, 0);
    offslider->setSliderStyle (Slider::LinearVertical);
    offslider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    offslider->addListener (this);

    addAndMakeVisible (label5 = new Label ("NoteOn Treshold",
                                           TRANS("NoteOn Treshold")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("NoteOff Treshold")));
    label6->setFont (Font (15.00f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (deltat = new Slider ("mindt"));
    deltat->setRange (0, 100, 1);
    deltat->setSliderStyle (Slider::LinearVertical);
    deltat->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    deltat->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Min dt")));
    label7->setFont (Font (15.00f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (keysc = new Slider ("keyscaling"));
    keysc->setRange (0, 10, 0);
    keysc->setSliderStyle (Slider::LinearVertical);
    keysc->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    keysc->addListener (this);

    addAndMakeVisible (keyscaling = new Label ("keyscaling",
                                               TRANS("Keyscaling")));
    keyscaling->setFont (Font (15.00f, Font::plain));
    keyscaling->setJustificationType (Justification::centredLeft);
    keyscaling->setEditable (false, false, false);
    keyscaling->setColour (TextEditor::textColourId, Colours::black);
    keyscaling->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	startTimer(33);
    //[/Constructor]
}

Guitar2midiAudioProcessorEditor::~Guitar2midiAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;
    inmeter = nullptr;
    label = nullptr;
    slider = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    offslider = nullptr;
    label5 = nullptr;
    label6 = nullptr;
    deltat = nullptr;
    label7 = nullptr;
    keysc = nullptr;
    keyscaling = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Guitar2midiAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Guitar2midiAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (448, 368, 100, 24);
    inmeter->setBounds (512, 40, 24, 144);
    label->setBounds (8, 272, 816, 24);
    slider->setBounds (40, 16, 56, 192);
    label2->setBounds (8, 304, 528, 24);
    label3->setBounds (8, 336, 520, 24);
    label4->setBounds (8, 368, 408, 24);
    offslider->setBounds (168, 16, 56, 192);
    label5->setBounds (24, 216, 88, 24);
    label6->setBounds (152, 216, 88, 24);
    deltat->setBounds (296, 16, 56, 192);
    label7->setBounds (296, 216, 72, 24);
    keysc->setBounds (416, 16, 56, 192);
    keyscaling->setBounds (408, 216, 80, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Guitar2midiAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton)
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
		getProcessor()->peak = 0;
		getProcessor()->aantalnullen = 0;
		getProcessor()->aantalnegatief = 0;
		getProcessor()->aantalpositief = 0;
		getProcessor()->nummessagessent = 0;
        //[/UserButtonCode_textButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void Guitar2midiAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		getProcessor()->threshold = slider->getValue();
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == offslider)
    {
        //[UserSliderCode_offslider] -- add your slider handling code here..
		getProcessor()->offtreshold = offslider->getValue();
        //[/UserSliderCode_offslider]
    }
    else if (sliderThatWasMoved == deltat)
    {
        //[UserSliderCode_deltat] -- add your slider handling code here..
		getProcessor()->mindt = deltat->getValue();
        //[/UserSliderCode_deltat]
    }
    else if (sliderThatWasMoved == keysc)
    {
        //[UserSliderCode_keysc] -- add your slider handling code here..
		getProcessor()->keysc = keysc->getValue();
        //[/UserSliderCode_keysc]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Guitar2midiAudioProcessorEditor::timerCallback()
{
	Guitar2midiAudioProcessor* ourProcessor = getProcessor();

	float peak = ourProcessor->peak;
	float rms = ourProcessor->rms;

	float aantalnullen = ourProcessor->aantalnullen;
	float aantalpieken = ourProcessor->aantalpieken;

	meterinupdate(peak, rms);
	label->setText("Nullen: " + (String)aantalnullen + " anders: " + (String)aantalpieken + " buffersize: " + (String)ourProcessor->buffersize +  " peak: " + (String)peak + " RMS: " + (String)rms, NotificationType::dontSendNotification);
	label2->setText("Postief: " + (String)ourProcessor->aantalpositief, NotificationType::dontSendNotification);
	label3->setText("Negatief: " + (String)ourProcessor->aantalnegatief, NotificationType::dontSendNotification);
	label4->setText("Midi Msgs verzonden: " + (String)ourProcessor->nummessagessent, NotificationType::dontSendNotification);
	//exchange any data you want between UI elements and the Plugin "ourProcessor"
}

void Guitar2midiAudioProcessorEditor::meterinupdate(float peak, float rms)
{
	inmeter->update(peak, rms);
}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Guitar2midiAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="Guitar2midiAudioProcessor&amp; ownerFilter"
                 variableInitialisers="AudioProcessorEditor(ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="3bf021f312f84267" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="448 368 100 24" buttonText="Reset"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <GENERICCOMPONENT name="Audio in meter" id="1d955084047e3654" memberName="inmeter"
                    virtualName="" explicitFocusOrder="0" pos="512 40 24 144" class="meter"
                    params=""/>
  <LABEL name="new label" id="f9a59d695dd4174f" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="8 272 816 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="7560a4f10e2790bb" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="40 16 56 192" min="0.0001" max="1"
          int="0" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="9e91e9fa9828560d" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="8 304 528 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="a4042044521f9b56" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="8 336 520 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="76aec5a288ec41a3" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="8 368 408 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="noteoff treshold" id="ad418f55bcf7424a" memberName="offslider"
          virtualName="" explicitFocusOrder="0" pos="168 16 56 192" min="9.9999999999999995e-007"
          max="1" int="0" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="NoteOn Treshold" id="a386073d2227aaae" memberName="label5"
         virtualName="" explicitFocusOrder="0" pos="24 216 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NoteOn Treshold" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="8831020abcd7d34a" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="152 216 88 24" edTextCol="ff000000"
         edBkgCol="0" labelText="NoteOff Treshold" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="mindt" id="25f679cc40c80915" memberName="deltat" virtualName=""
          explicitFocusOrder="0" pos="296 16 56 192" min="0" max="100"
          int="1" style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="5b8a1816078e26b4" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="296 216 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Min dt" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="keyscaling" id="1236bee43c18e568" memberName="keysc" virtualName=""
          explicitFocusOrder="0" pos="416 16 56 192" min="0" max="10" int="0"
          style="LinearVertical" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="keyscaling" id="8f61306b989ea60c" memberName="keyscaling"
         virtualName="" explicitFocusOrder="0" pos="408 216 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Keyscaling" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
