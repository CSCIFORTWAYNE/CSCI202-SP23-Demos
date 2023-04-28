#ifndef BLOCK_H
#define BLOCK_H
#include <string>
#include <ctime>
#include <functional>

class block
{
public:
    std::string getData();
    size_t getHash();
    block(int, std::string, size_t);

private:
    int blockNum;
    time_t nonce;
    std::string data;
    size_t prevHash;
    size_t currentHash;
    void calculateHash();
};

#endif