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

#ifndef __JUCE_HEADER_710FC36CEDCE5789__
#define __JUCE_HEADER_710FC36CEDCE5789__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "../Custom/KnobLookAndFeel.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TransposedDirectFormIifilterAudioProcessorEditor  : public AudioProcessorEditor,
                                                          public Timer,
                                                          public SliderListener,
                                                          public ComboBoxListener
{
public:
    //==============================================================================
    TransposedDirectFormIifilterAudioProcessorEditor (TransposedDirectFormIifilterAudioProcessor& owner);
    ~TransposedDirectFormIifilterAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	KnobLookAndFeel knobLookAndFeel;

	ScopedPointer<ResizableCornerComponent> win_resizer;	// Corner resizer
	ComponentBoundsConstrainer win_resizeLimits;			// Resizing limits

	TransposedDirectFormIifilterAudioProcessor& getProcessor() const
	{
		return static_cast<TransposedDirectFormIifilterAudioProcessor&>(processor);
	}

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> cutoffSlider;
    ScopedPointer<Slider> resonanceSlider;
    ScopedPointer<Slider> gainSlider;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> cutoffVal;
    ScopedPointer<Label> resVal;
    ScopedPointer<Label> gainVal;
    ScopedPointer<ComboBox> filterTypeCBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransposedDirectFormIifilterAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_710FC36CEDCE5789__
