#ifndef HUFFMANTREE
#define HUFFMANTREE

#include "HuffmanNode.h"
#include "Utils.h"
#include <string>
#include <queue>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <bitset>
class myComparator
{
  public:
    bool operator()(HuffmanNode node_1, HuffmanNode node_2)
    {
        return (node_1.getFrequency() > node_2.getFrequency());
    }
};

class HuffmanTree {
private:


public:
  

  HuffmanTree(); //default constructor - define in .cpp

  ~HuffmanTree(); //destructor - define in .cpp file

  // HuffmanTree(const HuffmanTree &ht); //Copy constructor

  // HuffmanTree &operator=(const HuffmanTree &other); //Assignment operator

  // bool operator==(const HuffmanTree &other) const;

  // HuffmanTree(HuffmanTree &&other); //Move constructor

  // HuffmanTree &operator=(const HuffmanTree &&other); //Move assignment operator

  std::unordered_map<char, int> buildFrequencyTable(std::string input);

  std::unordered_map<char, std::string> buildCodeTable(std::shared_ptr<HuffmanNode> root_node);

  std::string compress(std::string input_file_name, std::string output_file_name);

    std::shared_ptr<HuffmanNode> buildHuffmanTree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, myComparator> pq);
    void processNode(std::unordered_map<char, std::string> & table, std::shared_ptr<HuffmanNode> root_node, std::string prefix);
    std::string mapToString(std::unordered_map<char, std::string> map);
    // std::string compress(std::string file_name);
    void compressToFile(std::string input_file_name, std::string output_file_name);
    std::string compressToBits(std::string file_name, std::string output_file_name);
    std::string unpackBits(std::string file_name);
    std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, myComparator> ConstructPQ(std::unordered_map<char, int> table);
};
#endif
