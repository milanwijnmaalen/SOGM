normalizer: normalizer.cpp
	g++ `pkg-config --cflags sndfile` -std=c++11 -c normalizer.cpp
	g++ `pkg-config --libs sndfile` -o normalizer normalizer.o
