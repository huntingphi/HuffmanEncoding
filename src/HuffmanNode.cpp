#include "../include/HuffmanNode.h"

void HuffmanNode::setLeftChild(std::shared_ptr<HuffmanNode> child){
        this->left = child;
}
void HuffmanNode::setRigthtChild(std::shared_ptr<HuffmanNode> child){
        this->right = child;
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


HuffmanNode::HuffmanNode(char k, int f):key(k),frequency(f){
        //default constructor - define in .cpp

}

HuffmanNode::HuffmanNode(std::shared_ptr<HuffmanNode> left_child, std::shared_ptr<HuffmanNode> right_child):left(left_child),right(right_child){
        frequency = left_child->frequency + right_child->frequency;
}

HuffmanNode::~HuffmanNode()
{
        //destructor - define in .cpp file

}
HuffmanNode::HuffmanNode(const HuffmanNode &node):key(node.key),frequency(node.frequency){
        //Copy constructor
}

HuffmanNode& HuffmanNode::operator = (const HuffmanNode &other){
        //Assignment operator
        this->frequency = other.frequency;
        this->key = other.key;
        return *this;
}

HuffmanNode::HuffmanNode(HuffmanNode&& other):key(char('\0')),frequency(0), left(nullptr), right(nullptr){
        //Move constructor
        key = other.key;
        frequency = other.frequency;
        left = std::move(other.left);//std::make_shared<HuffmanNode>(std::move(other.left));
        right = std::move(other.right); //std::make_shared<HuffmanNode>(std::move(other.right));

        other.key = '\0';
        other.frequency = 0;
        other.left = nullptr;
        other.right = nullptr;

}
HuffmanNode& HuffmanNode::operator = (HuffmanNode&& other){
        //Move assignment operator
        if (this != &other){
                left = nullptr;
                right = nullptr;
                key = '\0';
                frequency = 0;
                
                key = other.key;
                frequency = other.frequency;
                left = std::move(other.left);   //std::make_shared<HuffmanNode>(std::move(other.left));
                right = std::move(other.right); //std::make_shared<HuffmanNode>(std::move(other.right));
                
                other.key = '\0';
                other.frequency = 0;
                other.left = nullptr;
                other.right = nullptr;
        }
}
