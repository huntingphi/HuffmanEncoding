#include "../include/HuffmanNode.h"

void HuffmanNode::setLeftChild(std::shared_ptr<HuffmanNode> child){
}
void HuffmanNode::setRigthtChild(std::shared_ptr<HuffmanNode> child){

}

char HuffmanNode::getKey(){
        return key;
}

int HuffmanNode::getFrequency(){
        return frequency;
}

std::shared_ptr<HuffmanNode> HuffmanNode::getLeftChild(){
        return right;
}
std::shared_ptr<HuffmanNode> HuffmanNode::getRightChild(){
        return left;        
}


HuffmanNode::HuffmanNode(char key, int frequency){
        //default constructor - define in .cpp
        this->key = key;
        this->frequency = frequency;

}


HuffmanNode::~HuffmanNode(){
        //destructor - define in .cpp file

}
HuffmanNode::HuffmanNode(const HuffmanNode &node){
        //Copy constructor
        this->frequency = node.frequency;
        this->key = node.key;
}

HuffmanNode& HuffmanNode::operator = (const HuffmanNode &other){
        //Assignment operator
        this->frequency = other.frequency;
        this->key = other.key;
        return *this;
}

HuffmanNode::HuffmanNode(HuffmanNode&& other){
        //Move constructor
}
HuffmanNode& HuffmanNode::operator = (const HuffmanNode&& other){
        //Move assignment operator
}
