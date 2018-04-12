#include "../include/HuffmanTree.h"



// bool HuffmanTree::operator==(const HuffmanTree &other) const{
//         return true;
// }
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
        counters[char(-1)] = 1;//Insert a character that represents the end of the line
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


//Recursively iterate through the nodes and their children and update the map accordingly
void HuffmanTree::processNode(std::unordered_map<char, std::string>& table,std::shared_ptr<HuffmanNode> root_node,std::string prefix)
{
        char parent_key = (*root_node).getKey();

        if (parent_key != char(-2))
        {
                table[parent_key] = prefix;
        }

        if((*root_node).getLeftChild()!=nullptr){
                processNode(table, (*root_node).getLeftChild(), prefix+"0");
        }
        if((*root_node).getRightChild()!=nullptr){
                processNode(table, (*root_node).getRightChild(), prefix+"1");

        }
}

//String representation of the map
std::string HuffmanTree::mapToString(std::unordered_map<char, std::string> map)
{
        std::string output_string = "{\"fieldCount\":\""+std::to_string(map.size())+std::string("\"},\n{\"table\":[\n");
        
        for (auto key : map)
        {
                output_string+="\t{\"key\":\"";
                output_string.append(1,key.first);
                output_string+=std::string("\", \"code\":\"");
                output_string+=key.second+"\" },\n";
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
        std::shared_ptr<HuffmanNode> root_node = buildHuffmanTree(ConstructPQ(buildFrequencyTable(input_string)));
        std::unordered_map<char, std::string> code_table;
        code_table = buildCodeTable(root_node);
        ///////////////////////////////////////////////////

        /*****************Build output string*************/
        std::string output_string = "";
        for(char c:input_string){
                output_string+=code_table.at(c);
        }
        

        return output_string;
}

void HuffmanTree::compressToFile(std::string input_file_name, std::string output_file_name)
{
        ///////////////////Read file here//////////
        std::string input_string = Utils::readFile(input_file_name);
        ///////////////////////////////////////////

        /****************Construct code table**************/
        std::shared_ptr<HuffmanNode> root_node = buildHuffmanTree(ConstructPQ(buildFrequencyTable(input_string)));
        std::unordered_map<char, std::string> code_table;
        code_table = buildCodeTable(root_node);
        ///////////////////////////////////////////////////

        /*****************Build output string*************/
        std::string output_string = "";
        for(char c:input_string){
                output_string+=code_table.at(c);
        }

        Utils::writeToFile(output_file_name + ".hc", output_string.c_str());
        Utils::writeToFile((output_file_name + ".hdr"), mapToString(code_table).c_str());
}


std::string HuffmanTree::compressToBits(std::string file_name, std::string output_file_name)
{
        
        std::string input_string = compress(file_name,output_file_name);
        std::string file_path = "assets/" + output_file_name;
        std::ofstream output_file(file_path, std::ios::out | std::ios::binary);
        std::ofstream output_file_data(file_path+".data"); //single int as header which lists the number of bits in the file
        int number_of_bits = input_string.size();
        output_file_data<<number_of_bits;
        std::stringstream input_stream(input_string);
        char bit_stream[9];
        char c;

        while (input_stream.get(bit_stream, 9))
        {
                for (int i = 7; i >= 0; i--)
                {
                        if (bit_stream[7 - i] == '1')
                        {
                                c |= 1 << i;
                        }
                        else
                        {
                                c &= ~(1 << i);
                        }
                }
                output_file << c;
        }
        
        return input_string;
}

std::string HuffmanTree::unpackBits(std::string file_name){
        std::string filepath = "assets/"+file_name;//+".hc.bits";
        std::ifstream input_file(filepath, std::ios::in | std::ios::binary);
        
        std::stringstream input_stream;

        char c;
        while (input_file.get(c))
        {
                for (int i = 7; i >= 0; i--)
                {
                        input_stream<< ((c >> i) & 1);
                }
        }
        input_file.close();
        std::string binary_data = input_stream.str();
        std::ifstream input_file_data(filepath+".data");
        int size = 0;
        input_file_data>>size;
        input_file_data.close();

        return binary_data.substr(0,size);
}

    HuffmanTree::HuffmanTree()
{
        //default constructor - define in .cpp
}

HuffmanTree::~HuffmanTree(){
        //destructor - define in .cpp file
}

// HuffmanTree::HuffmanTree(const HuffmanTree &ht){
//         //Copy constructor
// }

// HuffmanTree& HuffmanTree::operator = (const HuffmanTree& other){
//         //Assignment operator
//         return *this;//TODO: FIX THIS
// }

// HuffmanTree::HuffmanTree(HuffmanTree&& other){
//         //Move constructor

// }

// HuffmanTree& HuffmanTree::operator = (const HuffmanTree&& other){
//         //Move assignment operator
// }





