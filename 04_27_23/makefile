all: block blockchain
	g++ -pedantic-errors -g main.cpp block blockchain -o main
block: block.h block.cpp
	g++ -pedantic-errors -g -c block.cpp -o block
blockchain: blockchain.h blockchain.cpp block
	g++ -pedantic-errors -g -c blockchain.cpp -o blockchain