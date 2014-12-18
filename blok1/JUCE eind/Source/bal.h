#pragma once
#include "oscillator.h";

class bal : public oscillator
{
public:
	bal();
	void setX(int x);
	void setY(int y);
	void setvisible(bool);
	bool getvisible();
	float getX();
	float getY();
	void setGradientId(int);
	int getGradientId();

private:
	int x = 0;
	int y = 0;
	int gradid;
	bool visible = false;
};
