#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "HuffmanNode.h"
#include <string>
#include <queue>
#include <unordered_map>
class HuffmanTree {
private:


public:
HuffmanTree(); //default constructor - define in .cpp

~HuffmanTree(); //destructor - define in .cpp file

HuffmanTree(const HuffmanTree &ht); //Copy constructor

HuffmanTree& operator = (const HuffmanTree& other); //Assignment operator

HuffmanTree(HuffmanTree&& other); //Move constructor

HuffmanTree& operator = (const HuffmanTree&& other); //Move assignment operator

std::unordered_map<char, int> buildFrequencyTable(std::string input);

HuffmanNode* buildHuffmanTree(std::unordered_map<char, int> table);




};
#endif
