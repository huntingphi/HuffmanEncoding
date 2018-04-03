#include "../include/HuffmanTree.h"


HuffmanTree::HuffmanTree(){
        //default constructor - define in .cpp
}

HuffmanTree::~HuffmanTree(){
        //destructor - define in .cpp file
}

HuffmanTree::HuffmanTree(const HuffmanTree &ht){
        //Copy constructor
}

HuffmanTree& HuffmanTree::operator = (const HuffmanTree& other){
        //Assignment operator
}

HuffmanTree::HuffmanTree(HuffmanTree&& other){
        //Move constructor

}

HuffmanTree& HuffmanTree::operator = (const HuffmanTree&& other){
        //Move assignment operator
}

std::unordered_map<char, int> HuffmanTree::buildFrequencyTable(std::string input){ //Tested: Y
        std::unordered_map<char, int> counters;
        for(char c : input) {
                counters[c]++;
        }
        counters[char(-1)] = 1;
        return counters;
}

HuffmanNode* HuffmanTree::buildHuffmanTree(std::unordered_map<char, int> table){ //Tested: N



}
