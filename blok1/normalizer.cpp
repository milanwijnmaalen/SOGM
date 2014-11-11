#include <sndfile.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

float buffer[100000000];

enum MyEnum
{
	ARG_NAME = 0, ARG_INFILE, ARG_OUTFILE, NUM_ARGS
};

void printarray(float* dearray, int max)
{
	for (size_t i = 1; i < max; i++)
	{
		cout << "index " << i << " waarde: " << dearray[i] << endl;
	}
}

void normalize(float* dearray, int length)
{
	float temp = 0;
	for (size_t i = 1; i < length; i++)
	{
		if (fabs(dearray[i]) > temp)
		{
			temp = fabs(dearray[i]);
		}
	}

	cout << "Peek: " << temp << endl;

	for (size_t i = 1; i < length; i++)
	{
		if (temp != 0){
			dearray[i] = dearray[i] / temp;
		}
	}


}


//argc = aantal argumenten, argv = waarden
int main(int argc, char** argv)
{
	cout << argc;
	if (argc < NUM_ARGS)
	{
		cout << "Argument 1: In filename, Argument 2: Outfilename." << endl;;
	}
	else
	{

		char* inFileName = argv[ARG_INFILE]; //"Greenstereo.wav";

		SF_INFO sfinfo;
		SNDFILE* inFile = sf_open(inFileName, SFM_READ, &sfinfo); //SF_INFO bevat info soundfile bv sfinfo.channels; nieuw bestand: SNDFILE* out = sf_open(path, SFM_WRITE, &sfInfo); dan zelf sfInfo vullen: sfinfo.channels, sfinfo.samplerate enz

		int numchannels = sfinfo.channels;
		int numframes = sfinfo.frames;
		int buffersize = 100000000;

		sf_readf_float(inFile, buffer, numframes); //readf = in frames, read = in samples. buffer[framenr * channels + channel];

		cout << "aantal frames: " << numframes << endl;

		sf_close(inFile);


		normalize(buffer, numframes * numchannels);

		SNDFILE* outfile = sf_open(argv[ARG_OUTFILE], SFM_WRITE, &sfinfo);

		cout << "samplerate: " << sfinfo.samplerate << endl;

		cout << sf_writef_float(outfile, buffer, numframes) << " frames geschreven" << endl;

		sf_close(outfile);
	}
	return 0;
}