#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "base64.hpp"

struct TestTable {
    std::string message;
    std::string encoded;
};

std::vector<TestTable> tests{
    { .message = "A", .encoded = "QQ==" },
    { .message = "1", .encoded = "MQ==" },
    { .message = "huasdkfla", .encoded = "aHVhc2RrZmxh" },
    { .message = "abcdefghijklmnopqrstuvwxyz0123456789", .encoded = "YWJjZGVmZ2hpamtsbW5vcHFyc3R1dnd4eXowMTIzNDU2Nzg5" },
};

TEST_CASE("Encode string to base64", "[Encode]") {
    for (int i = 0; i < tests.size(); i++) {
        REQUIRE(Base64::encode(tests.at(i).message) == tests.at(i).encoded);
    }
}