#pragma once
class oscillator
{
public:
	oscillator();
	~oscillator();
	int calculatesine(float*buffer, int frames, int SR, float a, float d, float s, float r);
	void setfreq(float f);
	void activate(bool aan);
	void setpan(float p);
	float getpan();
	float getfreq();

private:
	float* buffer;
	int frames;
	float freq = 500;
	bool on = false;
	float newf = 500;
	float pan = 0.5;
	int i = 0;
	int t = 0;
	int rt;
	
	//bool changingfreq = false;
	//int freqtimer;

	
	bool release = false;

};

