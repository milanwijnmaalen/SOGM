//f(x) = sin((1/2P)pi x)
//P = periode
//f = 480Hz
//T = 1 / f = 1 / 480

#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int SR = 48000; //SampleRate
float freq = 480; //Te plotten frequentie
float P = SR / freq; //lengte 1 periode in samples
float x = P / 2; 
float length = P; //lengte te plotten, P => plot 1 periode, SR = plot 1 seconde, of aantal samples.

int main(int argc, char** argv)
{
	ofstream file;
	file.open("test.txt");
	for(int sample=0; sample < length; sample++){
		float frame = sin(M_PI * sample / x);
		file << sample << ", " << frame << "\n";
	}
	file.close();
//	cin >> freq;
	return 0;
}
