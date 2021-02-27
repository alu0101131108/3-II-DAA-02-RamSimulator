#include "../lib/Memory.hpp"

Memory::Memory(const int &size) : registers_(size, 0)
{}

void Memory::read(const int &registerIndex, int &value)
{}

void Memory::write(const int &registerIndex, const int &value)
{}

void Memory::toString(std::string &memoryAsString)
{}