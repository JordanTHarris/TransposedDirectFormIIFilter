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
	TransDirectFormIIFilter();
	TransDirectFormIIFilter(int type, double Fc, double Q, double peakGaindB);
	~TransDirectFormIIFilter();
	void setType(int type);
	void setQ(double Q);
	void setFc(double Fc);
	void setPeakGain(double peakGaindB);
	void setFilter(int type, double Fc, double Q, double peakGaindB);
	float processLeft(float in);
	float processRight(float in);

	void setSampleRate(double sampleRate);

protected:
	void calcFilter(void);

	int type;
	double a0, a1, a2, b1, b2;
	double Fc, Q, peakGain;
	double z1_L, z2_L, z1_R, z2_R;
	double sampleRate;
};

inline float TransDirectFormIIFilter::processLeft(float in) {
	double out = in * a0 + z1_L;
	z1_L = (in * a1) + z2_L - (b1 * out);
	z2_L = (in * a2) - (b2 * out);
	return out;
}

inline float TransDirectFormIIFilter::processRight(float in) {
	double out = in * a0 + z1_R;
	z1_R = (in * a1) + z2_R - (b1 * out);
	z2_R = (in * a2) - (b2 * out);
	return out;
}

//==============================================================================

#endif  // TRANSDIRECTFORMIIFILTER_H_INCLUDED
