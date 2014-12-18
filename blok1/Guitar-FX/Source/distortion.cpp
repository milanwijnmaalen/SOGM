#include "distortion.h"
#include <algorithm>
#include <math.h>

using namespace std;

distortion::distortion()
{
}

distortion::~distortion()
{
}

void distortion::distort(float* buffer, float amount, int frames)
{
	for (size_t i = 0; i < frames; i++)
	{
		buffer[i] = max(min(buffer[i], amount), -1 * amount);
	}


}
