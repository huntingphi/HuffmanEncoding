#ifndef UTILS
#define UTILS

#include <string>
#include <fstream>
namespace Utils {

std::string readFile(std::string fileName);

void writeToFile(std::string file_name, const char *data);
}



#endif
