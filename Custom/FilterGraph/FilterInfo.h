/*
  ==============================================================================

    FilterInfo.h
    
    Sean Enderby

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include <complex>
#include <vector>

#ifndef double_E
#define double_E 2.71828183
#endif
//====================================================================================
enum FilterType
{
	LowPass,
	HighPass
};
    
enum BandType
{
    LowShelf,
    HighShelf,
    Peak
};

//==============================================================================
class FilterResponse
{
public:
    FilterResponse (double magnitudeInit, double phaseInit);
    ~FilterResponse();
    
    double magnitudeValue, phaseValue;
};

//============================================================================
class FilterInfo : public IIRFilter
{
public:    
    FilterInfo();
    ~FilterInfo();
    
    void setSampleRate (double sampleRate);
    void setGain (double gain);
    
    FilterResponse getResponse (double inputFrequency) const;
    
    void zeroCoeffs();
    
    void setFilter (double frequency, FilterType filterType);
    void setEqBand (double frequency, double Q, float gain, BandType eqType);
    
    void setCustom (std::vector <double> numCoeffs, std::vector <double> denCoeffs);
    
private:
    double fs;
    int numNumeratorCoeffs, numDenominatorCoeffs;

    std::vector <double> numeratorCoeffs;
    std::vector <double> denominatorCoeffs;
    double gainValue;
};