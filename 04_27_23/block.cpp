#include "block.h"

std::string block::getData()
{
    return data;
}

size_t block::getHash()
{
    calculateHash();
    return currentHash;
}

block::block(int blockNum, std::string data, size_t prevHash)
{
    this->blockNum = blockNum;
    this->nonce = time(NULL);
    this->data = data;
    this->prevHash = prevHash;
    calculateHash();
}

void block::calculateHash()
{
    std::hash<std::string> str_hash;
    std::string hashString = std::to_string(blockNum) + std::to_string(nonce) + data + std::to_string(prevHash);
    currentHash = str_hash(hashString);
}
