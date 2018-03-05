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

// std::vector<std::vector<int>> SliceBinary(std::string text) {
void SliceBinary(std::string text) {
    std::vector<int> binary;
    binary = TextToBinary(text);

    std::vector< std::vector<int> > chunks;
    for (int i = 0; i < (binary.size() / 6); i++) {
        std::vector<int> slice;
        chunks.push_back(slice);
    }

    int currentChunk = -1;
    for (int i = 0; i < binary.size(); i++) {
        if (i % 6 != 0) {
            chunks.at(currentChunk).push_back(binary.at(i));
        } else {
            currentChunk++;
            chunks.at(currentChunk).push_back(binary.at(i));
        }
    }    

    for (int i = 0; i < chunks.size(); i++) {
        std::cout << chunks.at(i).size() << "\n";
        for (int j = 0; j < chunks.at(i).size(); j++) {
            std::cout << chunks.at(i).at(j);
        }
        std::cout << "\n";
    }
}