#include "delay.h"
#include <algorithm>
#include <math.h>
using namespace std;



delay::delay()
{
}

delay::~delay()
{
}

void delay::Delay(float* buffer, int time, float feedback, int frames)
{


	for (size_t i = 0; i < frames; i++)
	{
		temp[i] = buffer[i];
	}



	for (int i = 0; i < frames; i++)
	{

		if (i < time)
		{
			buffer[i] = buffer[i] + feedback * vorige[frames + i - time];

		}
		else
		{
			buffer[i] = buffer[i] + feedback * buffer[i - time];

			//buffer[i] = temp[i] + feedback * vorige[frames + i - time];
			
		}
	}


	for (size_t i = 0; i < frames; i++)
	{
		vorige[i] = buffer[i];
	}

}
