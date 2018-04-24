#include "base64.hpp"
#include "bintext.hpp"

std::string Base64::encode(std::string text) {
    std::vector<int> binary = TextToBinary(text);
    std::vector< std::vector<int> > chunks = BinaryTo6BitChunks(binary);
    bool needToFix = FixLastChunk(&chunks);
    return EncodeToBase64(chunks, needToFix);
}