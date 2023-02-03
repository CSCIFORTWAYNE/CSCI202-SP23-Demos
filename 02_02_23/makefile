all: laptop
	g++ -pedantic-errors -g main.cpp laptop -o main
laptop: laptop.h laptop.cpp
	g++ -pedantic-errors -g -c laptop.cpp -o laptop
clean:
	rm laptop
	rm main