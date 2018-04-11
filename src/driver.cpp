#include <iostream>
#include "../include/driver.h"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: huffencode <input file><output file>";
        return 0;
    }
    HuffmanTree htree;
    htree.compressToBits(argv[1], argv[2]);
    return 1;
}