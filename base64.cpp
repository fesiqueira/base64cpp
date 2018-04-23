#include "bintext.hpp"

const char base64table[] = 
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

class Base64 {
public:
    std::string encode(std::string);
    std::string decode(std::string); 
};

std::string Base64::encode(std::string msg) {
    std::vector<int> binaryMsg;

    binaryMsg = TextToBinary(msg);
}