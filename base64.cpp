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

std::string Encode(std::string text) {
    std::vector<int> binary = TextToBinary(text);
    std::vector< std::vector<int> > slices = SliceIntVector(binary, 6);
    std::string encoded;

    bool isNormalized = NormalizeSlice(&slices);
    
    std::vector<int> decimal = SliceToDecimal(slices);
    for (int i = 0; i < decimal.size(); i++) {
        encoded.push_back(base64table[decimal.at(i)]);
    }

    if (isNormalized) {
        encoded.push_back('=');
        if (encoded.length() < 4) {
            encoded.push_back('=');
        }
    }

    return encoded;
}