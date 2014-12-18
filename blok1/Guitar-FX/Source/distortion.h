#pragma once

#include "amplifier.h"

class distortion
{
public:
	distortion();
	~distortion();
	void distort(float* buffer, float amount, int frames);

private:
	float vorige[10000];
	float temp[10000];
};

