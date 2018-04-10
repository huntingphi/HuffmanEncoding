#ifndef HUFFMANNODE
#define HUFFMANNODE
#include <memory>
#include <iostream>
class HuffmanNode {

private:
std::shared_ptr<HuffmanNode> left_child_node;
std::shared_ptr<HuffmanNode> right_child_node;
int frequency;
char key = char(-2); //Either a char, or EOF char or NOT_CHAR sentinal


public:

/***********************BIG SIX**********************/
HuffmanNode(char key, int frequency); //default constructor - define in .cpp

HuffmanNode(std::shared_ptr<HuffmanNode> left_child, std::shared_ptr<HuffmanNode> right_child); //internal parent node constructor

HuffmanNode();

~HuffmanNode(); //destructor - define in .cpp file

HuffmanNode(const HuffmanNode &node); //Copy constructor

HuffmanNode& operator = (const HuffmanNode& other); //Assignment operator

HuffmanNode(HuffmanNode&& other); //Move constructor

HuffmanNode& operator = ( HuffmanNode&& other); //Move assignment operator
///////////////////////////////////////////////////

/****************RELATIONAL OPERATOR OVERLOADING***************/

bool operator == (const HuffmanNode &other) const;
bool operator != (const HuffmanNode &other) const;
///////////////////////////////////////////////////

/******************ACCESSORS*********************/

char getKey() const;
int getFrequency() const;
std::string toString() const;
std::shared_ptr<HuffmanNode> getLeftChild() const;
std::shared_ptr<HuffmanNode> getRightChild() const;
///////////////////////////////////////////////////

/******************MUTATORS********************/

void setLeftChild(std::shared_ptr<HuffmanNode> child_left);
void setRightChild(std::shared_ptr<HuffmanNode> child_right);
void setFrequency(int frequency);
void setKey(char key);
///////////////////////////////////////////////////
};
#endif
