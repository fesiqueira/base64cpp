#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "base64.hpp"

TEST_CASE("Encode string to base64", "[Encode]") {
    REQUIRE(Encode("A") == "QQ==");
    REQUIRE(Encode("1") == "MQ==");
    REQUIRE(Encode("felipe") == "ZmVsaXBl");
    REQUIRE(Encode("huasdkfla") == "aHVhc2RrZmxh");
}