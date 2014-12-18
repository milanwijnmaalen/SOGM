#pragma once

class delay
{
public:
	delay();
	~delay();
	void Delay(float* buffer, int time, float feedback, int frames);

private:
	float vorige[10000];
	float temp[10000];
};

