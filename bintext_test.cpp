#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "bintext.hpp"

struct TestTable {
    std::string in;
    std::vector<int> out;
};

std::vector<TestTable> tests{
    { .in = "A", .out = {0,1,0,0,0,0,0,1} },
    { .in = "Ab", .out = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0} },    
    { .in = "Abc", .out = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1} },
    { .in = "Abcde", .out = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1} },
    { .in = "Abcde0", .out = {0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,1,0,0,0,1,1,0,0,1,0,1,0,0,1,1,0,0,0,0} }
};

TEST_CASE("Convert binary to text", "[BinaryToText]") {
    for (int i = 0; i < tests.size(); i++) {
        REQUIRE(TextToBinary(tests.at(i).in) == tests.at(i).out);
    }
}