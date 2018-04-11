#include "../include/HuffmanTree.h"



bool HuffmanTree::operator==(const HuffmanTree &other) const{
        return true;
}
std::unordered_map<char, int> HuffmanTree::buildFrequencyTable(std::string input){ //Tested: Y
        std::unordered_map<char, int> counters;
        for (char c : input)
        {
                counters[c]++;
        }
        if(counters.count(char(-1))!=0){
                throw std::logic_error("EOF char used has been found in the file");
                
        }
        if (counters.count(char(-2)) != 0)
        {
                throw std::logic_error("NO_KEY char used has been found in the file");
        }
        counters[char(-1)] = 1;//Insert a character that signifies the end of the line
        return counters;
}

std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, myComparator> HuffmanTree::ConstructPQ(std::unordered_map<char, int> table)
{
        std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, myComparator> pq;
        for (auto c : table)
        {
                pq.push(HuffmanNode(c.first, c.second));
        }
        return pq;
}

std::shared_ptr<HuffmanNode> HuffmanTree::buildHuffmanTree(std::priority_queue<HuffmanNode, std::vector<HuffmanNode>, myComparator> pq){ //Tested: Y
        while(pq.size()>1){
                HuffmanNode node1 = pq.top();
                pq.pop();
                HuffmanNode node2 = pq.top();
                pq.pop();
                pq.push(HuffmanNode(std::make_shared<HuffmanNode>(node1),std::make_shared<HuffmanNode>(node2)));
        }
        return std::make_shared<HuffmanNode>(pq.top());
}

std::unordered_map<char, std::string> HuffmanTree::buildCodeTable(std::shared_ptr<HuffmanNode> root_node){
        std::unordered_map<char, std::string> table;
        processNode(table,root_node,"");
        return table;
}

void HuffmanTree::processNode(std::unordered_map<char, std::string>& table,std::shared_ptr<HuffmanNode> root_node,std::string prefix)
{
        char parent_key = (*root_node).getKey();

        if (parent_key != char(-2))
        {
                table[parent_key] = prefix;
        }

        if((*root_node).getLeftChild()!=nullptr){
                processNode(table, (*root_node).getLeftChild(), prefix+"0");
                // char left_child_key = (*(*root_node).getLeftChild()).getKey();
                // table[left_child_key] = std::string("0")+prefix;
        }
        if((*root_node).getRightChild()!=nullptr){
                processNode(table, (*root_node).getRightChild(), prefix+"1");
                // char right_child_key = (*(*root_node).getRightChild()).getKey();

        }
}

std::string HuffmanTree::mapToString(std::unordered_map<char, std::string> map)
{
        std::string output_string = "{\"fieldCount\":\""+static_cast<int>(map.size())+std::string("\"},\n\"{\"table\":[\n");
        for (auto key : map)
        {
                output_string+="{\"key\":\""+key.first+std::string("\", \"value\":\"")+key.second+"\" },\n";
                // std::cout<<"key: "<<key.first<<"value: "<<key.second<<std::endl;
        }
        output_string+="]}";

        return output_string;
}

std::string HuffmanTree::compress(std::string input_file_name,std::string output_file_name){
        
        ///////////////////Read file here//////////
        std::string input_string = Utils::readFile(input_file_name);
        ///////////////////////////////////////////

        /****************Construct code table**************/
        HuffmanTree htree;
        std::shared_ptr<HuffmanNode> root_node = htree.buildHuffmanTree(htree.ConstructPQ(htree.buildFrequencyTable(input_string)));
        std::unordered_map<char, std::string> code_table;
        code_table = htree.buildCodeTable(root_node);
        ///////////////////////////////////////////////////

        /*****************Build output string*************/
        std::string output_string = "";
        // htree.mapToString(code_table);
        for(char c:input_string){
                // if(*code_table.at(c).c_str() != char(-1))
                output_string+=code_table.at(c);
        }
        // std::cout<<input_string<<std::endl;
        // std::cout<<output_string<<std::endl;
        Utils::writeToFile(output_file_name,output_string.c_str());

        return output_string;
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





