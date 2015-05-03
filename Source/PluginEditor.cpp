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
TransposedDirectFormIifilterAudioProcessorEditor::TransposedDirectFormIifilterAudioProcessorEditor (TransposedDirectFormIifilterAudioProcessor& owner)
    : AudioProcessorEditor(owner)
{
    addAndMakeVisible (cutoffSlider = new Slider ("CutoffFreq"));
    cutoffSlider->setTooltip (TRANS("Logarithmic control of the filter\'s cutoff frequency."));
    cutoffSlider->setRange (22.5064, 130.096, 0);
    cutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    cutoffSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cutoffSlider->addListener (this);

    addAndMakeVisible (resonanceSlider = new Slider ("Resonance"));
    resonanceSlider->setTooltip (TRANS("Filter\'s resonance control. Self-oscillation at 1.0."));
    resonanceSlider->setRange (0, 1, 0);
    resonanceSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    resonanceSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    resonanceSlider->addListener (this);

    addAndMakeVisible (gainSlider = new Slider ("PeakGain"));
    gainSlider->setTooltip (TRANS("Peak gain for the Peak, Lowshelf, and Highshelf filters."));
    gainSlider->setRange (-60, 10, 0);
    gainSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    gainSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Cutoff (Hz)")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Resonance")));
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

    addAndMakeVisible (cutoffVal = new Label ("cutoff value",
                                              TRANS("label text")));
    cutoffVal->setFont (Font (15.00f, Font::plain));
    cutoffVal->setJustificationType (Justification::centred);
    cutoffVal->setEditable (false, false, false);
    cutoffVal->setColour (TextEditor::textColourId, Colours::black);
    cutoffVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (resVal = new Label ("resonance value",
                                           TRANS("label text")));
    resVal->setFont (Font (15.00f, Font::plain));
    resVal->setJustificationType (Justification::centred);
    resVal->setEditable (false, false, false);
    resVal->setColour (TextEditor::textColourId, Colours::black);
    resVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (gainVal = new Label ("gain value",
                                            TRANS("label text")));
    gainVal->setFont (Font (15.00f, Font::plain));
    gainVal->setJustificationType (Justification::centred);
    gainVal->setEditable (false, false, false);
    gainVal->setColour (TextEditor::textColourId, Colours::black);
    gainVal->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (filterTypeCBox = new ComboBox ("filter type"));
    filterTypeCBox->setTooltip (TRANS("Select the filter type used."));
    filterTypeCBox->setEditableText (false);
    filterTypeCBox->setJustificationType (Justification::centredLeft);
    filterTypeCBox->setTextWhenNothingSelected (String::empty);
    filterTypeCBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    filterTypeCBox->addItem (TRANS("Lowpass"), 1);
    filterTypeCBox->addItem (TRANS("Highpass"), 2);
    filterTypeCBox->addItem (TRANS("Bandpass"), 3);
    filterTypeCBox->addItem (TRANS("Notch"), 4);
    filterTypeCBox->addItem (TRANS("Peak"), 5);
    filterTypeCBox->addItem (TRANS("Lowshelf"), 6);
    filterTypeCBox->addItem (TRANS("Highshelf"), 7);
    filterTypeCBox->addListener (this);


    //[UserPreSize]

    //[/UserPreSize]

    setSize (500, 200);


    //[Constructor] You can add your own custom stuff here..

	// Add the window resizer component for the bottom right of the UI
	addAndMakeVisible(win_resizer = new ResizableCornerComponent(this, &win_resizeLimits));
	win_resizeLimits.setSizeLimits(owner.lastUIWidth_m, owner.lastUIHeight_m, 500, 200);

	setSize(owner.lastUIWidth_m, owner.lastUIHeight_m);

	// Use custom knob image strip for each slider.
	cutoffSlider->setLookAndFeel(&knobLookAndFeel);
	resonanceSlider->setLookAndFeel(&knobLookAndFeel);
	gainSlider->setLookAndFeel(&knobLookAndFeel);

	// Set the ComboBox to select the Lowpass Filter by default
	filterTypeCBox->setSelectedItemIndex(0, sendNotification);

	startTimerHz(512);

    //[/Constructor]
}

TransposedDirectFormIifilterAudioProcessorEditor::~TransposedDirectFormIifilterAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    cutoffSlider = nullptr;
    resonanceSlider = nullptr;
    gainSlider = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    cutoffVal = nullptr;
    resVal = nullptr;
    gainVal = nullptr;
    filterTypeCBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TransposedDirectFormIifilterAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TransposedDirectFormIifilterAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    cutoffSlider->setBounds (20, 72, 60, 60);
    resonanceSlider->setBounds (120, 72, 60, 60);
    gainSlider->setBounds (220, 72, 60, 60);
    label->setBounds (15, 40, 65, 24);
    label2->setBounds (115, 40, 65, 24);
    label3->setBounds (215, 40, 65, 24);
    cutoffVal->setBounds (14, 144, 72, 24);
    resVal->setBounds (114, 144, 72, 24);
    gainVal->setBounds (214, 144, 72, 24);
    filterTypeCBox->setBounds (328, 40, 150, 24);
    //[UserResized] Add your own custom resize handling here..
	getProcessor().lastUIWidth_m = getWidth();
	getProcessor().lastUIHeight_m = getHeight();
    //[/UserResized]
}

void TransposedDirectFormIifilterAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == cutoffSlider)
    {
        //[UserSliderCode_cutoffSlider] -- add your slider handling code here..
		getProcessor().setParameterNotifyingHost(TransposedDirectFormIifilterAudioProcessor::kCutoffFreqParam,
												(float)cutoffSlider->getValue());
        //[/UserSliderCode_cutoffSlider]
    }
    else if (sliderThatWasMoved == resonanceSlider)
    {
        //[UserSliderCode_resonanceSlider] -- add your slider handling code here..
		getProcessor().setParameterNotifyingHost(TransposedDirectFormIifilterAudioProcessor::kFilterResParam,
												(float)resonanceSlider->getValue());
        //[/UserSliderCode_resonanceSlider]
    }
    else if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
		getProcessor().setParameterNotifyingHost(TransposedDirectFormIifilterAudioProcessor::kPeakGaindBParam,
												(float)gainSlider->getValue());
        //[/UserSliderCode_gainSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void TransposedDirectFormIifilterAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == filterTypeCBox)
    {
        //[UserComboBoxCode_filterTypeCBox] -- add your combo box handling code here..
		getProcessor().setParameterNotifyingHost(TransposedDirectFormIifilterAudioProcessor::kFilterTypeParam,
											(int)filterTypeCBox->getSelectedItemIndex());
        //[/UserComboBoxCode_filterTypeCBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TransposedDirectFormIifilterAudioProcessorEditor::timerCallback()
{
	TransposedDirectFormIifilterAudioProcessor& ourProcessor = getProcessor();

	cutoffSlider->setValue(ourProcessor.cutoff_m, dontSendNotification);
	resonanceSlider->setValue(ourProcessor.resonance_m, dontSendNotification);
	gainSlider->setValue(ourProcessor.peakGaindB_m, dontSendNotification);

	filterTypeCBox->setSelectedItemIndex(ourProcessor.filterType_m, dontSendNotification);

	// Note: convert pitch to frequency to display on the label
	cutoffVal->setText(String(pitchToFreq(ourProcessor.cutoff_m)) + " Hz", dontSendNotification);
	resVal->setText(String(ourProcessor.resonance_m), dontSendNotification);
	gainVal->setText(String(ourProcessor.peakGaindB_m) + " dB", dontSendNotification);

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TransposedDirectFormIifilterAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="TransposedDirectFormIifilterAudioProcessor&amp; owner"
                 variableInitialisers="AudioProcessorEditor(owner)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="500" initialHeight="200">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="CutoffFreq" id="648750270b7670ed" memberName="cutoffSlider"
          virtualName="" explicitFocusOrder="0" pos="20 72 60 60" tooltip="Logarithmic control of the filter's cutoff frequency."
          min="22.50637" max="130.09578200000001" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Resonance" id="577486c89cc0202" memberName="resonanceSlider"
          virtualName="" explicitFocusOrder="0" pos="120 72 60 60" tooltip="Filter's resonance control. Self-oscillation at 1.0."
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PeakGain" id="5f7024e3655032c8" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="220 72 60 60" tooltip="Peak gain for the Peak, Lowshelf, and Highshelf filters."
          min="-60" max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="33577796e39c63e8" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="15 40 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff (Hz)" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8658d26cc045c768" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="115 40 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Resonance" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e663a55ba20d5ec6" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="215 40 65 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Peak Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="cutoff value" id="268afbfb55db8d67" memberName="cutoffVal"
         virtualName="" explicitFocusOrder="0" pos="14 144 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="resonance value" id="385c4b243b85aeb1" memberName="resVal"
         virtualName="" explicitFocusOrder="0" pos="114 144 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="gain value" id="be0333f31aafb1e" memberName="gainVal" virtualName=""
         explicitFocusOrder="0" pos="214 144 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <COMBOBOX name="filter type" id="8257fa5126e6325e" memberName="filterTypeCBox"
            virtualName="" explicitFocusOrder="0" pos="328 40 150 24" tooltip="Select the filter type used."
            editable="0" layout="33" items="Lowpass&#10;Highpass&#10;Bandpass&#10;Notch&#10;Peak&#10;Lowshelf&#10;Highshelf"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
