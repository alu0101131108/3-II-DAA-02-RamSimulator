#include "../lib/Memory.hpp"

Memory::Memory(const int &size) : registers_(size, 0)
{}

void Memory::read(const int &registerIndex, int &value)
{
  value = registers_[registerIndex];
}

void Memory::write(const int &registerIndex, const int &value)
{
  registers_[registerIndex] = value;
}

void Memory::toString(std::string &memoryAsString)
{
  
}