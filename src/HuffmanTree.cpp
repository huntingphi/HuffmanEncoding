#include "../include/HuffmanTree.h"

class myComparator
{
      public:
        bool operator()(HuffmanNode node_1, HuffmanNode node_2)
        {
                return (node_1.getFrequency() > node_2.getFrequency());
        }
};

std::unordered_map<char, int> HuffmanTree::buildFrequencyTable(std::string input){ //Tested: Y
        std::unordered_map<char, int> counters;
        for (char c : input)
        {
                counters[c]++;
        }
        counters[char(-1)] = 1;
        return counters;
}

std::shared_ptr<HuffmanNode> HuffmanTree::buildHuffmanTree(std::unordered_map<char, int> table)
{ //Tested: N
        std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, myComparator > pq;
        for (auto c:table){
                pq.push(HuffmanNode(c.first,c.second));
        }
        return std::make_shared<HuffmanNode>(pq.top());
}

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
        return *this;//TODO: FIX THIS
}

HuffmanTree::HuffmanTree(HuffmanTree&& other){
        //Move constructor

}

HuffmanTree& HuffmanTree::operator = (const HuffmanTree&& other){
        //Move assignment operator
}





