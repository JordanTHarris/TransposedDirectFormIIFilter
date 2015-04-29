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
	float process(float in);


protected:
	void calcFilter(void);

	int type;
	double a0, a1, a2, b1, b2;
	double Fc, Q, peakGain;
	double z1, z2;
};

inline float TransDirectFormIIFilter::process(float in) {
	double out = in * a0 + z1;
	z1 = (in * a1) + z2 - (b1 * out);
	z2 = (in * a2) - (b2 * out);
	return out;
}

//==============================================================================

#endif  // TRANSDIRECTFORMIIFILTER_H_INCLUDED
