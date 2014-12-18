#include "bal.h"


bal::bal()
{
}

void bal::setX(int newx)
{
	x = newx;
}

void bal::setY(int newy)
{
	y = newy;
}
void bal::setvisible(bool newvis)
{
	visible = newvis;
}

bool bal::getvisible()
{
	return visible;
}


float bal::getX()
{
	return x;
}

float bal::getY()
{
	return y;
}

void bal::setGradientId(int newid)
{
	gradid = newid;
}

int bal::getGradientId()
{
	return gradid;
}