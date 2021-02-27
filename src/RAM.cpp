#include "../lib/RAM.hpp"

RAM::RAM(const int &inputBandSize, const int &outputBandSize, const int &memorySize)
: inputBand_(inputBandSize), outputBand_(outputBandSize), memory_(memorySize), pc_(0)
{}

void RAM::loadInstructionsFromFile(const std::string &filename)
{}
