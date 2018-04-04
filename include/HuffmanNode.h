#ifndef HUFFMANNODE
#define HUFFMANNODE
#include <memory>
class HuffmanNode {

private:
std::shared_ptr<HuffmanNode> left;
std::shared_ptr<HuffmanNode> right;
int frequency;
char key; //Either a char, or EOF char or NOT_CHAR sentinal


public:
HuffmanNode(char key, int frequency); //default constructor - define in .cpp

HuffmanNode(std::shared_ptr<HuffmanNode> left_child, std::shared_ptr<HuffmanNode> right_child); //internal parent node constructor

    ~HuffmanNode(); //destructor - define in .cpp file

HuffmanNode(const HuffmanNode &node); //Copy constructor

HuffmanNode& operator = (const HuffmanNode& other); //Assignment operator

HuffmanNode(HuffmanNode&& other); //Move constructor

HuffmanNode& operator = ( HuffmanNode&& other); //Move assignment operator


char getKey();

int getFrequency();

void setLeftChild(std::shared_ptr<HuffmanNode> child);
void setRigthtChild(std::shared_ptr<HuffmanNode> child);

std::shared_ptr<HuffmanNode> getLeftChild();
std::shared_ptr<HuffmanNode> getRightChild();
};
#endif
