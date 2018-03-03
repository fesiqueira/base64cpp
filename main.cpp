#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

const char kBase64Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

std::vector<int> TextToBinary(std::string text) {
    std::vector<int> output;
    std::reverse(text.begin(), text.end());

    for (int i = 0; i < text.size(); i++) {
        for (int j = 0; j < 8; ++j) {      
            output.push_back((text.at(i) >> j) & 1);
        } 
    }

    std::reverse(output.begin(), output.end());

    return output;
}

std::string BinaryToText(std::vector<int> binary) {
    int totalBytes = binary.size() / 8;
    std::string text;

    for (int i = 0; i < totalBytes; i++) {
        int asciiValue = 0;
        for (int j = i * 8, k = 7; j < (i + 1) * 8, k >= 0; j++, k--) {
            asciiValue += binary.at(j) * std::pow(2, k);
        }
        text.push_back(char(asciiValue));
    }

    return text;
}

int main() {
    std::string text = "felipe";
    std::vector<int> textToBin;
    std:: string binToText;

    textToBin = TextToBinary(text);

    for (int i = 0; i < textToBin.size(); i++) {
        std::cout << textToBin.at(i);
    }
    std::cout << "\n";

    binToText = BinaryToText(textToBin);

    std::cout << binToText << "\n";
}
