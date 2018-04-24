#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>

const char base64table[] = 
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
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

std::vector<int> SliceToDecimal(std::vector< std::vector<int> > slices) {
    std::vector<int> decimalSlice;

    for (int i = 0; i < slices.size(); i++) {
        int decimalValue = 0;
        std::vector<int> slice = slices.at(i);
        std::reverse(slice.begin(), slice.end());

        for (int j = 0; j < slices.at(i).size(); j++) {
            decimalValue += slice.at(j) * std::pow(2, j);
        }
        
        decimalSlice.push_back(decimalValue);
    }

    return decimalSlice;
}

// SliceIntVector will slice a vector<int> as many times as possible, based on the chunkLength
std::vector< std::vector<int> > SliceIntVector(std::vector<int> vctr, float sliceLength) {
    int totalSlices = ceil(vctr.size() / sliceLength);

    std::vector< std::vector<int> > slices;

    // initialize the slices
    for (int i = 0; i < totalSlices; i++) {
        std::vector<int> slice;
        slices.push_back(slice);
    }

    int currentSlice = -1;
    for (int i = 0; i < vctr.size(); i++) {
        if (i % (int)sliceLength != 0) {
            slices.at(currentSlice).push_back(vctr.at(i));
        } else {
            currentSlice++;
            slices.at(currentSlice).push_back(vctr.at(i));
        }
    }

    return slices;
}

std::vector< std::vector<int> > BinaryTo6BitChunks(std::vector<int> binary) {
    return SliceIntVector(binary, 6);
    // return chunks;
}

std::string BinaryToText(std::vector<int>  binary) {
    std::string text;
    std::vector<int> asciiSlice;
    std::vector< std::vector<int> > slices;

    slices = SliceIntVector(binary, 8);

    asciiSlice = SliceToDecimal(slices);

    for (int i = 0; i < asciiSlice.size(); i++) {
        text.push_back(char(asciiSlice.at(i)));
    }

    return text;
}

bool FixLastChunk(std::vector< std::vector<int> >* slices) {
    if (slices->back().size() == 6) {
        return false;
    }
    while(slices->back().size() < 6) {
        slices->back().push_back(0);
    }
    return true;
}

std::string EncodeToBase64(std::vector< std::vector<int> > chunks, bool needToFix) {
    std::string encoded;
    std::vector<int> decimals = SliceToDecimal(chunks);
    
    for (int i = 0; i < decimals.size(); i++) {
        encoded.push_back(base64table[decimals.at(i)]);
    }

    if (needToFix) {
        encoded.push_back('=');
        if (encoded.length() < 4) {
            encoded.push_back('=');
        }
    }

    return encoded;
}