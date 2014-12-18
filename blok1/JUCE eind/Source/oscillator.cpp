#include "oscillator.h"
#define _USE_MATH_DEFINES
#include <math.h>

oscillator::oscillator()
{
}


oscillator::~oscillator()
{
}

int oscillator::calculatesine(float* buffer, int frames, int SR, float a = 0, float d = 0, float s = 1, float r = 0) //a,d en r in milliseconden, s tussen 0 en 1
{
	a = a * 44.1;
	d = d * 44.1;
	r = r * 44.1;



	float A = 0;
	if (on == true)
	{
		A = 0.5;
	}


	for (int teller = 0; teller < frames; teller++)
	{
		if (release == true && rt <= r)
		{
			if (t < a + d)
			{
				s = A;
			}

			t = a + d + r;
			float releasestap = s / r;
			A = s - (rt * releasestap);
			rt++;
			if (rt == r)
			{
				A = 0;
			}
		}
		else if (on == false && release == false)
		{
			A = 0;
		}

		else if (on == true && t < a)
		{
			float attackstap = 1 / a;
			A = t * attackstap;
		}
		else if (on == true && d > 0 && t >= a && t < a + d)
		{
			float decaystap = (1 - s) / d;
			A = 1 - ((t - a) * decaystap);
		}
		else if (on == true && t >= a + d)
		{
			A = s;
		}
		
		else{
			release = false;
			A = 0;
			rt = 0;
		}


		buffer[teller] = A * sin(M_PI * i / ((SR / freq) / 2));

		if (buffer[teller] <= 0 && buffer[teller] > -0.05 && freq != newf && sin(M_PI * (i + 1) / ((SR / freq) / 2)) > 0)
		{
			freq = newf;
			i = 0;
			buffer[teller] = 0;
		}


		t++;

		i++;
	}

	return i;
}

void oscillator::setfreq(float f)
{
	newf = f;
}

void oscillator::activate(bool aan)
{

	on = aan;
	if (release == true)
	{
		release = false;
		rt = 0;
		t = 0;
	}


	if (aan == false)
	{
		release = true;
		rt = 0;
	}
}

void oscillator::setpan(float p)
{
	pan = p;
}

float oscillator::getpan()
{
	return pan;
}

float oscillator::getfreq()
{
	return freq;
}