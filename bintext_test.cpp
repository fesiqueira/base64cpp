#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bintext.hpp"

struct TestTable {
    std::string text;
    std::vector<int> binary;
};

std::vector<TestTable> tests{
    { .text = "A", .binary = {0,1,0,0,0,0,0,1} },
    { .text = "Ab", .binary = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0} },    
    { .text = "Abc", .binary = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1} },
    { .text = "Abcde", .binary = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1} },
    { .text = "Abcde0", .binary = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0} }
};

TEST_CASE("Convert binary to text", "[TextToBinary]") {
    for (int i = 0; i < tests.size(); i++) {
        REQUIRE(TextToBinary(tests.at(i).text) == tests.at(i).binary);
    }
}

TEST_CASE("Convert text to binary", "[BinaryToText]") {
    for (int i = 0; i < tests.size(); i++) {
        REQUIRE(BinaryToText(tests.at(i).binary) == tests.at(i).text);
    }
}