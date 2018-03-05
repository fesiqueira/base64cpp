#include <iostream>
#include <bintext.h>

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

    SliceBinary("felipe");
}
