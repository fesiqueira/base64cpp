#include <iostream>
#include <bintext.h>

int main() {
    std::string text = "felipe";
    std::vector<int> binary;
    std::vector< std::vector<int> > slices;

    binary = TextToBinary(text);

    for (int i = 0; i < binary.size(); i++) {
        std::cout << binary.at(i);
    }
    std::cout << "\n";

    BinaryToText(binary);
}
