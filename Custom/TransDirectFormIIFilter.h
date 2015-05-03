/*
  ==============================================================================

	TransDirectFormIIFilter.h
	Created: 28 Apr 2015 3:16:59pm
	Author:  Jordan

  ==============================================================================
*/

#ifndef TRANSDIRECTFORMIIFILTER_H_INCLUDED
#define TRANSDIRECTFORMIIFILTER_H_INCLUDED

#define _USE_MATH_DEFINES 

#include <cmath>
#include "Utilities\DspUtilities.h"

using std::pow;
using std::tan;
using std::sqrt;

//==============================================================================
enum {
	bq_type_lowpass = 0,
	bq_type_highpass, 
	bq_type_bandpass,
	bq_type_notch,
	bq_type_peak,
	bq_type_lowshelf,
	bq_type_highshelf
};

//==============================================================================
class TransDirectFormIIFilter {
public:
	// Create and initialize the filter with default values defined in constructor.
	TransDirectFormIIFilter();

	// Initialize the filter with specific (static) parameters. Useful for
	// using as a static filter; not modulating parameters.
	TransDirectFormIIFilter(int type, double Fc, double res, double peakGaindB);

	~TransDirectFormIIFilter();

	/*
	Sets the type of the filter. This filter can choose between 7 different
	types using the enums listed below or the int given to each.
	0: bq_type_lowpass
	1: bq_type_highpass
	2: bq_type_bandpass
	3: bq_type_notch
	4: bq_type_peak
	5: bq_type_lowshelf
	6: bq_type_highshelf
	*/
	void setType(int type);

	// Used for setting the resonance amount. Range: (0-1)
	void setResonance(double resonance);

	// Used for changing the filter's cutoff parameter (Hz)
	void setFc(double Fc);

	/**
	*	Used for changing the peak gain (dB) of some filter types:
	*	Peak (bq_type_peak)
	*	Lowshelf (bq_type_lowshelf)
	*	Highshelf (bq_type_highshelf)
	*/
	void setPeakGain(double peakGaindB);

	// Statically set the filters parameters.
	void setFilter(int type, double Fc, double res, double peakGaindB);

	/**
	*	Performs the actual processing for one sample of data, on one channel.
	*	If 2 channels are needed (stereo), use the appropriate process function
	*	for the given channel (left & right)
	*/
	float processLeft(float in);

	/**
	*	Performs the actual processing for one sample of data, on one channel.
	*	If 2 channels are needed (stereo), use the appropriate process function
	*	for the given channel (left & right)
	*/
	float processRight(float in);

	// Set the sample rate used by the host. Needs to be used to accurately
	// calculate the coefficients of the filter from the cutoff.
	void setSampleRate(double sampleRate);

protected:
	// Calculate the coefficients for the filter. 
	// Uses different coefficients for different filter types
	void calcFilter(void);

	int type;							// filters type (LP, HP, BP, etc.)
	double a0, a1, a2, b1, b2;			// coefficients
	double Fc, Q, peakGain;				// parameters
	double z1_L, z2_L, z1_R, z2_R;		// filter's states (unit delays) for each channel
	double sampleRate;
};

inline float TransDirectFormIIFilter::processLeft(float in) {
	// Performs the actual processing for one sample of data, on one channel.
	// If 2 channels are needed (stereo), use the appropriate process function
	// for the given channel (left & right)
	double out = in * a0 + z1_L;
	z1_L = (in * a1) + z2_L - (b1 * out);
	z2_L = (in * a2) - (b2 * out);
	return out;
}

inline float TransDirectFormIIFilter::processRight(float in) {
	// Performs the actual processing for one sample of data, on one channel.
	// If 2 channels are needed (stereo), use the appropriate process function
	// for the given channel (left & right)
	double out = in * a0 + z1_R;
	z1_R = (in * a1) + z2_R - (b1 * out);
	z2_R = (in * a2) - (b2 * out);
	return out;
}

//==============================================================================

#endif  // TRANSDIRECTFORMIIFILTER_H_INCLUDED
