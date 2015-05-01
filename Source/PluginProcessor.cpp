/*
  ==============================================================================

	This file was auto-generated by the Introjucer!

	It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

const float defaultType = bq_type_lowpass;
const float defaultCutoff = 1000.0f;
const float defaultResonance = 0.7f;
const float defaultGain = 0.0f;

//==============================================================================
TransposedDirectFormIifilterAudioProcessor::TransposedDirectFormIifilterAudioProcessor()
{
	// Set variables to default values
	filterType_m = defaultType;
	cutoff_m = defaultCutoff;
	resonance_m = defaultResonance;
	peakGaindB_m = defaultGain;

	// Update filter with the default values

	directFormFilter.setType(filterType_m);
	directFormFilter.setFc(cutoff_m);
	directFormFilter.setResonance(resonance_m);
	directFormFilter.setPeakGain(peakGaindB_m);
	
	lastUIWidth_m = 500;
	lastUIHeight_m = 200;

	sampleRate = getSampleRate();
	directFormFilter.setSampleRate(sampleRate);
}

TransposedDirectFormIifilterAudioProcessor::~TransposedDirectFormIifilterAudioProcessor()
{
}

//==============================================================================
const String TransposedDirectFormIifilterAudioProcessor::getName() const
{
	return JucePlugin_Name;
}

int TransposedDirectFormIifilterAudioProcessor::getNumParameters()
{
	return kNumParameters;
}

float TransposedDirectFormIifilterAudioProcessor::getParameter (int index)
{
	switch (index) {
	case kFilterTypeParam:		return filterType_m;
	case kCutoffFreqParam:		return cutoff_m;
	case kFilterResParam:		return resonance_m;
	case kPeakGaindBParam:		return peakGaindB_m;
	default:					return 0.0;
	}
}

void TransposedDirectFormIifilterAudioProcessor::setParameter (int index, float newValue)
{
	switch (index) {
	case kFilterTypeParam:
		filterType_m = newValue;
		directFormFilter.setType(filterType_m);
		break;
	case kCutoffFreqParam:
		cutoff_m = newValue;
		directFormFilter.setFc(cutoff_m);
		break;
	case kFilterResParam:
		resonance_m = newValue;
		directFormFilter.setResonance(resonance_m);
		break;
	case kPeakGaindBParam:
		peakGaindB_m = newValue;
		directFormFilter.setPeakGain(peakGaindB_m);
		break;
	default:
		break;
	}
}

float TransposedDirectFormIifilterAudioProcessor::getParameterDefaultValue(int index)
{
	switch (index) {
	case kFilterTypeParam:		return defaultType;
	case kCutoffFreqParam:		return defaultCutoff;
	case kFilterResParam:		return defaultResonance;
	case kPeakGaindBParam:		return defaultGain;
	default:					return 0.0;
	}
}

const String TransposedDirectFormIifilterAudioProcessor::getParameterName (int index)
{
	switch (index) {
	case kFilterTypeParam:		return "filter type";
	case kCutoffFreqParam:		return "cutoff frequency";
	case kFilterResParam:		return "resonance";
	case kPeakGaindBParam:		return "peak gain";
	default:					break;
	}

	return String();
}

const String TransposedDirectFormIifilterAudioProcessor::getParameterText (int index)
{
	return String(getParameter(index), 2);		// parameter value, # decimal places
}

const String TransposedDirectFormIifilterAudioProcessor::getInputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

const String TransposedDirectFormIifilterAudioProcessor::getOutputChannelName (int channelIndex) const
{
	return String (channelIndex + 1);
}

bool TransposedDirectFormIifilterAudioProcessor::isInputChannelStereoPair (int index) const
{
	return true;
}

bool TransposedDirectFormIifilterAudioProcessor::isOutputChannelStereoPair (int index) const
{
	return true;
}

bool TransposedDirectFormIifilterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
	return true;
   #else
	return false;
   #endif
}

bool TransposedDirectFormIifilterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
	return true;
   #else
	return false;
   #endif
}

bool TransposedDirectFormIifilterAudioProcessor::silenceInProducesSilenceOut() const
{
	return false;
}

double TransposedDirectFormIifilterAudioProcessor::getTailLengthSeconds() const
{
	return 0.0;
}

int TransposedDirectFormIifilterAudioProcessor::getNumPrograms()
{
	return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
				// so this should be at least 1, even if you're not really implementing programs.
}

int TransposedDirectFormIifilterAudioProcessor::getCurrentProgram()
{
	return 0;
}

void TransposedDirectFormIifilterAudioProcessor::setCurrentProgram (int index)
{
}

const String TransposedDirectFormIifilterAudioProcessor::getProgramName (int index)
{
	return String();
}

void TransposedDirectFormIifilterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TransposedDirectFormIifilterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	// Use this method as the place to do any pre-playback
	// initialisation that you need..
	sampleRate = getSampleRate();
	directFormFilter.setSampleRate(sampleRate);

	directFormFilter.setType(filterType_m);
	directFormFilter.setFc(cutoff_m);
	directFormFilter.setResonance(resonance_m);
	directFormFilter.setPeakGain(peakGaindB_m);
}

void TransposedDirectFormIifilterAudioProcessor::releaseResources()
{
	// When playback stops, you can use this as an opportunity to free up any
	// spare memory, etc.
}

void TransposedDirectFormIifilterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	// This is the place where you'd normally do the guts of your plugin's
	// audio processing...

	if (getNumInputChannels() < 2) {
	}
	else {
		float* leftData = buffer.getWritePointer(0);
		float* rightData = buffer.getWritePointer(1);
		for (long i = 0; i < buffer.getNumSamples(); ++i) {
			const float inL = leftData[i];
			const float inR = rightData[i];
			leftData[i] = directFormFilter.processLeft(inL);
			rightData[i] = directFormFilter.processRight(inR);
		}
	}

	// In case we have more outputs than inputs, this code clears any output
	// channels that didn't contain input data, (because these aren't
	// guaranteed to be empty - they may contain garbage).
	// I've added this to avoid people getting screaming feedback
	// when they first compile the plugin, but obviously you don't need to
	// this code if your algorithm already fills all the output channels.
	for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
		buffer.clear (i, 0, buffer.getNumSamples());
}

//==============================================================================
bool TransposedDirectFormIifilterAudioProcessor::hasEditor() const
{
	return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TransposedDirectFormIifilterAudioProcessor::createEditor()
{
	return new TransposedDirectFormIifilterAudioProcessorEditor (*this);
}

//==============================================================================
void TransposedDirectFormIifilterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	// You should use this method to store your parameters in the memory block.
	// You could do that either as raw data, or use the XML or ValueTree classes
	// as intermediaries to make it easy to save and load complex data.

	// Create an out XML element...
	XmlElement xml{ "JTHPLUGINSETTINGS" };

	// add some attributes to it...
	xml.setAttribute("uiWidth", lastUIWidth_m);
	xml.setAttribute("uiHeight", lastUIHeight_m);
	xml.setAttribute("filterType", filterType_m);
	xml.setAttribute("cutoffFrequency", cutoff_m);
	xml.setAttribute("resonance", resonance_m);
	xml.setAttribute("peakGain", peakGaindB_m);

	// then use this helper function to stuff it into the binary block and return it...
	copyXmlToBinary(xml, destData);
}

void TransposedDirectFormIifilterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	// You should use this method to restore your parameters from this memory block,
	// whose contents will have been created by the getStateInformation() call.

	// This getXmlFromBinary() helper function retrieves our XML from the binary blob..
	ScopedPointer<XmlElement> xmlState{ getXmlFromBinary(data, sizeInBytes) };

	if (xmlState != nullptr) {

		// make sure that it's actually our type of XML object...
		if (xmlState->hasTagName("JTHPLUGINSETTINGS")) {

			// now pull out our parameters...
			lastUIWidth_m = xmlState->getIntAttribute("uiWidth", lastUIWidth_m);
			lastUIHeight_m = xmlState->getIntAttribute("uiHeight", lastUIHeight_m);

			filterType_m = xmlState->getIntAttribute("filterType", filterType_m);
			cutoff_m = (float)xmlState->getDoubleAttribute("cutoffFrequency", cutoff_m);
			resonance_m = (float)xmlState->getDoubleAttribute("resonance", resonance_m);
			peakGaindB_m = (float)xmlState->getDoubleAttribute("peakGain", peakGaindB_m);

			// Update filter
			directFormFilter.setType(filterType_m);
			directFormFilter.setFc(cutoff_m);
			directFormFilter.setResonance(resonance_m);
			directFormFilter.setPeakGain(peakGaindB_m);
		}
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
	return new TransposedDirectFormIifilterAudioProcessor();
}
