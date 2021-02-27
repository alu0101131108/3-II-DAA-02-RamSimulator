#include "../lib/Band.hpp"

Band::Band(const int &size) : cells_(size, 0), headPointer_(0)
{}

void Band::read(int &value)
{
  value = cells_[headPointer_];
  headPointer_++;
}

void Band::write(const int &value)
{
  cells_[headPointer_] = value;
  headPointer_++;
}

void Band::loadFromFile(const std::string &filename)
{}

void Band::saveToFile(const std::string &filename)
{}