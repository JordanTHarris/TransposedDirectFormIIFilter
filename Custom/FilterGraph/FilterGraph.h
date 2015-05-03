/*
  ==============================================================================

    FilterGraph.h
    
    Sean Enderby

  ==============================================================================
*/

#ifndef __FILTERGRAPH_H_3CCF0ED1__
#define __FILTERGRAPH_H_3CCF0ED1__

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterInfo.h"

//==============================================================================
class FilterGraph    : public Component,
                       public SettableTooltipClient
{
public:
    FilterGraph (int numFilters);
    ~FilterGraph();
    
    enum TraceType
    {
        Magnitude,
        Phase
    };
    
    void paint (Graphics&);
    void resized();
    
    void setNumHorizontalLines (int newValue);
    void setFreqRange (float newLowFreq, float newHighFreq);
    
    void setFilterGain (int filterNum, double gain);
    void setFilter (int filterNum, double sampleRate, double frequency, FilterType filterType);
    void setEqBand (int filterNum, double sampleRate, double frequency, double Q, float gain, BandType eqType);
    void setCustom (int filterNum, double sampleRate, std::vector <double> numCoeffs, std::vector <double> denCoeffs);
    
    float xToFreq (float xPos);
    float freqToX (float freq);

    void setTraceColour (Colour newColour);
    
    float maxdB, maxPhas;
    Colour traceColour;
    TraceType traceType;
    
private:
    int numHorizontalLines;
    float lowFreq, highFreq;   
    double fs;
    int numFilters;
    
    void mouseMove (const MouseEvent &event);
    
    std::vector <FilterInfo> filterVector;
    
    Path gridPath, tracePath;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterGraph)
};
#endif  // __FILTERGRAPH_H_3CCF0ED1__
