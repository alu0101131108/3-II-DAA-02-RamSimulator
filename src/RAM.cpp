#include "../lib/RAM.hpp"

RAM::RAM(const int &inputBandSize, const int &outputBandSize, const int &memorySize)
: inputBand_(inputBandSize), outputBand_(outputBandSize), memory_(memorySize),
pc_(0), haltState_(false) 
{}

void RAM::readFromMemory(const int &registerIndex, int &value)
{
  memory_.read(registerIndex, value);
}

void RAM::writeToMemory(const int &registerIndex, const int &value)
{
  memory_.write(registerIndex, value);
}

void RAM::readFromInputBand(int &value)
{
  inputBand_.read(value);
}

void RAM::writeToOutputBand(const int &value)
{
  outputBand_.write(value);
}

void RAM::getLabelDirection(const std::string &label, int &direction)
{
  direction = labelMap_[label];
}

void RAM::setPc(const int &value)
{
  pc_ = value;
}

void RAM::incrementPc()
{
  pc_++;
}

void RAM::setHaltState(const bool &haltState)
{
  haltState_ = haltState;
}

void RAM::loadInstructionsFromFile(const std::string &filename)
{}