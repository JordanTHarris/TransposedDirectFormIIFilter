/*
*	Useful DSP utilities. For instance, calculating frequency from a given 
*	pitch (MIDI) value, or vice versa.
*/

#ifndef DSP_UTILITIES
#define DSP_UTILITIES

//-----------------------------------------------------------------------------

#include <cmath>

//-----------------------------------------------------------------------------

double pitchToFreq(double pitch)
{
	// Calculates the frequency of a given pitch (MIDI) value.
	return pow(2, (pitch - 69) / 12) * 440;
}

//-----------------------------------------------------------------------------

double freqToPitch(double freq)
{
	return 69 + 12 * log2(freq / 440);
}

//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
#endif  DSP_UTILITIES