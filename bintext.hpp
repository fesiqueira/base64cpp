#ifndef BINTEXT_HPP
#define BINTEXT_HPP

#include <vector>
#include <string>

std::vector<int> TextToBinary(std::string);

std::string BinaryToText(std::vector<int>);

std::vector<int> SliceToDecimal(std::vector< std::vector<int> >);

std::vector< std::vector<int> > SliceIntVector(std::vector<int>, float);

std::vector< std::vector<int> > BinaryTo6BitChunks(std::vector<int>);

bool FixLastChunk(std::vector< std::vector<int> > *);

std::string EncodeToBase64(std::vector< std::vector<int> >, bool);

#endif