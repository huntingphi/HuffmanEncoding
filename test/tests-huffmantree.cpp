#include "../include/catch.hpp"
#include "../include/HuffmanTree.h"
#include <iostream>


TEST_CASE("Tests buildFrequencyTable"){
        bool flag_1 = true;
        bool flag_2 = true;
        bool flag_3 = true;


        HuffmanTree htree;
        std::string input1 = "THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG";
        std::string input2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        std::string false_input = "THIS DOESN'T CORRESPOND TO THE MAP IT MUST FAIL";
        std::unordered_map<char,int> expected_1 = {
                {' ',8},{'A',1},{'B',1},{'C',1},{'D',1},{'E',3},{'F',1},{'G',1},{'H',2},{'I',1},{'J',1},{'K',1},{'L',1},{'M',1},{'N',1},{'O',4},{'P',1},{'Q',1},{'R',2},{'S',1},{'T',2},{'U',2},{'V',1},{'W',1},{'X',1},{'Y',1},{'Z',1},{char(-1),1}
        };

        std::unordered_map<char,int> expected_2 = {
                {'A',1},{'B',1},{'C',1},{'D',1},{'E',1},{'F',1},{'G',1},{'H',1},{'I',1},{'J',1},{'K',1},{'L',1},{'M',1},{'N',1},{'O',1},{'P',1},{'Q',1},{'R',1},{'S',1},{'T',1},{'U',1},{'V',1},{'W',1},{'X',1}, {'Y',1}, {'Z',1},{char(-1),1}
        };

        std::unordered_map<char,int> expected_3 = {{'A',1},{'B',1},{'C',1}};

        std::unordered_map<char,int> result_1 = htree.buildFrequencyTable(input1);
        std::unordered_map<char,int> result_2 = htree.buildFrequencyTable(input2);
        std::unordered_map<char,int> result_3 = htree.buildFrequencyTable("ABC"); //Must fail

        for (char c : input1) {
                try{
                        if(result_1.at(c) != expected_1.at(c)) {
                                std::cout << "=============Loop 1=============" << '\n';
                                std::cout << "character: "<<c << '\n';
                                std::cout << "expected frequency: "<<expected_1.at(c) << '\n';
                                std::cout << "found: "<<result_1.at(c) << '\n';
                                flag_1 = false;
                                break;
                        }
                }catch(const std::out_of_range& error) {
                        std::cout << "Test 1: character("<<c<<") not found in map" << '\n';
                        flag_1 = false;
                        break;
                }
        }

        for (char c : input2) {
                try{
                        if(result_2.at(c) != expected_2.at(c)) {
                                std::cout << "=============Loop 2=============" << '\n';
                                std::cout << "character: "<<c << '\n';
                                std::cout << "expected frequency: "<<expected_2.at(c) << '\n';
                                std::cout << "found: "<<result_2.at(c) << '\n';
                                flag_2 = false;
                                break;
                        }
                }catch(const std::out_of_range& error) {
                        std::cout << "Test 2: character("<<c<<") not found in map" << '\n';

                        flag_2 = false;
                        break;
                }
        }

        for (char c : false_input) {
                try{
                        if(result_3.at(c) != expected_3.at(c)) {
                                std::cout << "=============Loop 3=============" << '\n';
                                std::cout << "character: "<<c << '\n';
                                std::cout << "expected frequency: "<<expected_3.at(c) << '\n';
                                std::cout << "found: "<<result_3.at(c) << '\n';

                                flag_3 = false;
                                break;
                        }
                }catch(const std::out_of_range& error) {
                        std::cout << "Test 3: character("<<c<<") not found in map" << '\n';
                        flag_3 = false;
                        break;
                }
        }

        // std::cout << "resulting map size: "<<result_1.size()<<" expected map size: "<<expected_1.size()<< " string size: "<<input1.length() << '\n';
        REQUIRE((flag_1==true && result_1.size() == expected_1.size()));
        REQUIRE((flag_2==true && result_2.size() == expected_2.size()));
        REQUIRE(flag_3==false);



}


TEST_CASE("Test buildHuffmanTree"){
        HuffmanTree htree;
        htree.buildFrequencyTable("abbccc");

        HuffmanNode a('a', 1);
        std::shared_ptr<HuffmanNode> a_ptr = std::make_shared<HuffmanNode>(a);
        HuffmanNode b('b', 2);
        std::shared_ptr<HuffmanNode> b_ptr = std::make_shared<HuffmanNode>(b);
        HuffmanNode c('c', 3);
        std::shared_ptr<HuffmanNode> c_ptr = std::make_shared<HuffmanNode>(c);

        HuffmanNode end(char(-1), 1);
        std::shared_ptr<HuffmanNode> end_ptr = std::make_shared<HuffmanNode>(end);
        HuffmanNode it_1 = HuffmanNode(end_ptr,a_ptr);
        std::shared_ptr<HuffmanNode> it_1_ptr = std::make_shared<HuffmanNode>(it_1);
        HuffmanNode it_2 = HuffmanNode(b_ptr, it_1_ptr);
        std::shared_ptr<HuffmanNode> it_2_ptr = std::make_shared<HuffmanNode>(it_2);
        HuffmanNode it_3 = HuffmanNode(c_ptr,it_2_ptr);
        HuffmanNode expected_root = it_3;
        HuffmanNode resulting_root = *htree.buildHuffmanTree(htree.ConstructPQ(htree.buildFrequencyTable("abbccc")));

        REQUIRE( resulting_root == it_3);
}

TEST_CASE("Test buildCodeTable"){
        HuffmanTree htree;
        std::shared_ptr<HuffmanNode> resulting_root = htree.buildHuffmanTree(htree.ConstructPQ(htree.buildFrequencyTable("abbccc")));
        std::unordered_map<char,std::string> resulting_table;
        resulting_table = htree.buildCodeTable(resulting_root);
        std::unordered_map<char, std::string> expected_table_1 = {{'a',"111"},{'b',"10"},{'c',"0"},{char(-1),"110"}};
        REQUIRE(resulting_table.at('a')==expected_table_1.at('a'));
        REQUIRE(resulting_table.at('b') == expected_table_1.at('b'));
        REQUIRE(resulting_table.at('c') == expected_table_1.at('c'));
        REQUIRE(resulting_table.at(char(-1)) == expected_table_1.at(char(-1)));
}

TEST_CASE("Test compress")
{
        HuffmanTree htree;
        std::string resulting_output = htree.compressToBits("lorem.txt", "lorem");
        std::string expected_output = "1111010000";
        REQUIRE(resulting_output == expected_output);
}
