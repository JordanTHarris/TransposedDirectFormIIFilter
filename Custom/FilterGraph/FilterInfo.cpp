/*
  ==============================================================================

    FilterInfo.cpp
    
    Sean Enderby

  ==============================================================================
*/

#include "FilterInfo.h"
//==============================================================================
FilterResponse::FilterResponse (double magnitudeInit, double phaseInit)
{
    magnitudeValue = magnitudeInit;
    phaseValue = phaseInit;
}

FilterResponse::~FilterResponse()
{
}

//===============================================================================
FilterInfo::FilterInfo()
{
    fs = 44100;
    
    numeratorCoeffs.resize (1, 0);
    numeratorCoeffs [0] = 1;
    denominatorCoeffs.resize (1, 0);
    denominatorCoeffs [0] = 1;
    
    numNumeratorCoeffs = 1;
    numDenominatorCoeffs = 1;
    
    gainValue = 1;
}

FilterInfo::~FilterInfo()
{
}

void FilterInfo::setSampleRate (double sampleRate)
{
    fs = sampleRate;
}

void FilterInfo::setGain (double gain)
{
    gainValue = gain;
}

FilterResponse FilterInfo::getResponse (double inputFrequency) const
{
    std::complex <double> normalisedFrequency (0, (2 * double_Pi * inputFrequency / fs));
    std::complex <double> z = pow (double_E, normalisedFrequency);
    
    std::complex <double> num (0, 0);
    std::complex <double> den (0, 0);
    
    for (int numOrder = 0; numOrder < numNumeratorCoeffs; numOrder++)
    {
        num += numeratorCoeffs [numOrder] / pow (z, numOrder);
    }
    
    for (int denOrder = 0; denOrder < numDenominatorCoeffs; denOrder++)
    {
        den += denominatorCoeffs [denOrder] / pow (z, denOrder);
    }
    
    std::complex <double> transferFunction = num / den;
    
    return FilterResponse (abs (transferFunction) * gainValue, arg (transferFunction));
}

void FilterInfo::zeroCoeffs()
{
    for (int numOrder = 0; numOrder < numNumeratorCoeffs; numOrder++)
    {
        numeratorCoeffs [numOrder] = 0;
    }
    
    for (int denOrder = 1; denOrder < numDenominatorCoeffs; denOrder++)
    {
        denominatorCoeffs [denOrder] = 0;
    }
    
    denominatorCoeffs [0] = 1;
}
    
void FilterInfo::setFilter (double frequency, FilterType filterType)
{
    numNumeratorCoeffs = 3;
    numDenominatorCoeffs = 3;
        
    numeratorCoeffs.resize (3, 0);
    denominatorCoeffs.resize (3, 0);
        
    zeroCoeffs();
        
    switch (filterType)
    {
        case LowPass:
            makeLowPass (fs, frequency);
            break;
            
        case HighPass:
            makeHighPass (fs, frequency);
            break;
            
        default: break;
    }
        
    for (int numOrder = 0; numOrder < 3; numOrder++)
    {
        numeratorCoeffs [numOrder] = coefficients [numOrder];
    }
        
    for (int denOrder = 1; denOrder < 3; denOrder++)
    {
        denominatorCoeffs [denOrder] = coefficients [denOrder + 2];
    }
    
    gainValue = 1;
}

void FilterInfo::setEqBand (double frequency, double Q, float gain, BandType eqType)
{
    numNumeratorCoeffs = 3;
    numDenominatorCoeffs = 3;
        
    numeratorCoeffs.resize (3, 0);
    denominatorCoeffs.resize (3, 0);
   
    zeroCoeffs();
        
    switch (eqType)
    {
        case LowShelf:
            makeLowShelf (fs, frequency, Q, gain);
            break;
            
        case HighShelf:
            makeHighShelf (fs, frequency, Q, gain);
            break;
       
        case Peak:
            makeBandPass (fs, frequency, Q, gain);
            break;
           
        default: break;
    }
        
    for (int numOrder = 0; numOrder < 3; numOrder++)
    {
        numeratorCoeffs [numOrder] = coefficients [numOrder];
    }
        
    for (int denOrder = 1; denOrder < 3; denOrder++)
    {
        denominatorCoeffs [denOrder] = coefficients [denOrder + 2];
    }
    
    gainValue = 1;    
}

void FilterInfo::setCustom (std::vector <double> numCoeffs, std::vector <double> denCoeffs)
{
    numNumeratorCoeffs = numCoeffs.size();
    numDenominatorCoeffs = denCoeffs.size();
    
    numeratorCoeffs = numCoeffs;
    denominatorCoeffs = denCoeffs;
}