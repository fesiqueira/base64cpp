#ifndef BINTEXT_HPP
#define BINTEXT_HPP

#include <vector>
#include <string>

std::vector<int> TextToBinary(std::string);

std::vector<int> SliceToDecimal(std::vector< std::vector<int> >);

std::vector< std::vector<int> > SliceIntVector(std::vector<int>, float);

std::string BinaryToText(std::vector<int>);

void Encode(std::string);

#endif