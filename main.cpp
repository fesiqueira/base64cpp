#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

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

void BinaryToText(std::vector<int> binary) {
    int totalBytes = binary.size() / 8;
    std::reverse(binary.begin(), binary.end());

    for (int i = 0; i < totalBytes; i++) {
        int sum = 0;
        for (int j = i * 8, k = 0; j < (i + 1) * 8, k < 8; j++, k++) {
            std::cout << binary.at(j);
            sum += binary.at(j) * std::pow(2, k);
        }
        std::cout << "\n" << sum; 
        std::cout << "\n";
    }
}

int main() {
    std::string test = "felipe";

    std::vector<int> output = TextToBinary(test);

    for (int i = 0; i < output.size(); i++) {
        std::cout << output.at(i);
    }
    std::cout << "\n";

    BinaryToText(output);
}
