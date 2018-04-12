#include "../include/Utils.h"

using namespace Utils;

std::string Utils::readFile(std::string file_name){
        char *buffer;
        std::string filepath = "assets/" + file_name;
        std::ifstream input_file(filepath, std::ios::in | std::ios::binary);
        input_file.seekg(0, input_file.end);
        size_t length = input_file.tellg();
        input_file.seekg(0, input_file.beg);
        buffer = new char[length];
        input_file.read(buffer, length);
        return buffer;
}

void Utils::writeToFile(std::string file_name, const char *data)
{
        std::string file_path = "assets/"+file_name;
        std::ofstream output_file(file_path, std::ios::out | std::ios::binary);
        output_file<<data;
        // output_file.write(data,);
        output_file.close();
}
