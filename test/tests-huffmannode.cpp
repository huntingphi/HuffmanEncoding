#include "../include/catch.hpp"
#include "../include/HuffmanNode.h"


TEST_CASE("Tests constructor"){
        HuffmanNode node('A',1);
        REQUIRE(node.getKey()=='A');
        REQUIRE(node.getFrequency()==1);
}
