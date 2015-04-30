/*
  ==============================================================================

	This file was auto-generated by the Introjucer!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "../Custom/TransDirectFormIIFilter.h"


//==============================================================================
/**
*/
class TransposedDirectFormIifilterAudioProcessor  : public AudioProcessor
{
public:
	//==============================================================================
	TransposedDirectFormIifilterAudioProcessor();
	~TransposedDirectFormIifilterAudioProcessor();

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
    float getParameterDefaultValue (int index) override;
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

	//==============================================================================
	enum Parameters
	{
		kFilterTypeParam = 0,		// Type of filter (LP, HP, BP, etc.)
		kCutoffFreqParam,			// Filter's cutoff frequency (Hz)
		kFilterQParam,				// Filter's Q (resonance)
		kPeakGaindBParam,			// Peak gain of the filter (dB)

		kNumParameters				// Number of parameters
	};

	int filterType_m;
	float cutoff_m;
	float Q_m;
	float peakGaindB_m;

	// these are used to persist the UI's size - the values are stored along with the
	// filter's other parameters, and the UI component will update them when it gets
	// resized.
	int lastUIWidth_m, lastUIHeight_m;


private:
	TransDirectFormIIFilter directFormFilter;
	float sampleRate;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransposedDirectFormIifilterAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
