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

        // std::cout << "==========================Result 1==========================" << '\n';
        //
        // for( const auto& n : result_1 ) {
        //         std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
        // }
        // // std::cout << "==========================Result 2==========================" << '\n';
        // // for( const auto& n : result_2 ) {
        // //         std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
        // // }
        // std::cout << "==========================Expected==========================" << '\n';
        //
        // for( const auto& n : expected_1 ) {
        //         std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
        // }

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
        htree.buildFrequencyTable("abbcccddddeeee");
        REQUIRE(htree.buildHuffmanTree(htree.buildFrequencyTable("abbcccddddeeee"))==HuffmanNode('a',1));
}
