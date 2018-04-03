#include "../include/Utils.h"

using namespace Utils;

std::string Utils::readFile(std::string fileName){
        std::string filepath = "assets/"+fileName+".txt";
        std::ifstream in(filepath);

        //copy all characters, starting from the first in the file, until the next character is end of the stream.
        std::string contents((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
        return contents;
}
