#include <iostream>
#include "../include/driver.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: huffencode <input file><output file>";
        return 1;
    }
    HuffmanTree htree;
    htree.compressToFile(argv[1], argv[2]);
        htree.compressToBits(argv[1], argv[2]);
    return 0;
}