#ifndef BINTEXT_H
#define BINTEXT_H

#include <vector>
#include <string>

std::vector<int> TextToBinary(std::string);

std::vector<int> SliceToDecimal(std::vector< std::vector<int> >);

std::vector< std::vector<int> > SliceIntVector(std::vector<int>, float);

void BinaryToText(std::vector<int>);

#endif