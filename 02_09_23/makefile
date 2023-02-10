all: laptop stackTrace
	g++ -pedantic-errors -g main.cpp laptop stackTrace -o main
laptop: laptop.h laptop.cpp
	g++ -pedantic-errors -g -c laptop.cpp -o laptop
stackTrace: stackTrace.h stackTrace.cpp
	g++ -pedantic-errors -g -c stackTrace.cpp -o stackTrace