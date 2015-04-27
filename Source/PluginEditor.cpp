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
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor ()
{
    addAndMakeVisible (cutoffSlider = new Slider ("CutoffFreq"));
    cutoffSlider->setRange (0, 10, 0);
    cutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    cutoffSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cutoffSlider->addListener (this);

    addAndMakeVisible (peakSlider2 = new Slider ("PeakGain"));
    peakSlider2->setRange (0, 10, 0);
    peakSlider2->setSliderStyle (Slider::RotaryVerticalDrag);
    peakSlider2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    peakSlider2->addListener (this);

    addAndMakeVisible (QSlider = new Slider ("FilterQ"));
    QSlider->setRange (0, 10, 0);
    QSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    QSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    QSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Cutoff (Hz)")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Q")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Peak Gain")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    cutoffSlider = nullptr;
    peakSlider2 = nullptr;
    QSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    cutoffSlider->setBounds (20, 72, 60, 60);
    peakSlider2->setBounds (220, 72, 60, 60);
    QSlider->setBounds (120, 72, 60, 60);
    label->setBounds (15, 40, 65, 24);
    label2->setBounds (115, 40, 65, 24);
    label3->setBounds (215, 40, 65, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == cutoffSlider)
    {
        //[UserSliderCode_cutoffSlider] -- add your slider handling code here..
        //[/UserSliderCode_cutoffSlider]
    }
    else if (sliderThatWasMoved == peakSlider2)
    {
        //[UserSliderCode_peakSlider2] -- add your slider handling code here..
        //[/UserSliderCode_peakSlider2]
    }
    else if (sliderThatWasMoved == QSlider)
    {
        //[UserSliderCode_QSlider] -- add your slider handling code here..
        //[/UserSliderCode_QSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="300" initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="CutoffFreq" id="648750270b7670ed" memberName="cutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="20 72 60 60" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PeakGain" id="577486c89cc0202" memberName="peakSlider2"
          virtualName="" explicitFocusOrder="0" pos="220 72 60 60" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="FilterQ" id="5f7024e3655032c8" memberName="QSlider" virtualName=""
          explicitFocusOrder="0" pos="120 72 60 60" min="0" max="10" int="0"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="33577796e39c63e8" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="15 40 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8658d26cc045c768" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="115 40 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Q" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e663a55ba20d5ec6" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="215 40 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Peak Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
