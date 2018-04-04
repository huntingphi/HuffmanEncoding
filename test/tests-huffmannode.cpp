#include "../include/catch.hpp"
#include "../include/HuffmanNode.h"


TEST_CASE("Tests constructor"){
        HuffmanNode node('A',1);
        REQUIRE(node.getKey()=='A');
        REQUIRE(node.getFrequency()==1);
}

TEST_CASE("Tests parent constructor")
{
        std::shared_ptr<HuffmanNode> l(new HuffmanNode ('A', 1));
        std::shared_ptr<HuffmanNode> r(new HuffmanNode('B', 3));

        HuffmanNode node(l,r);
        REQUIRE(node.getFrequency() == 4);
}
