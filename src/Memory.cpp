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

void Memory::printRegisters()
{
  for (int i = 0; i < registers_.size(); i++)
  {
    if (i % 4 == 0)
    {
      std::cout << std::endl;
    }
    std::cout << "R" << i << ": |" << registers_[i] << "| ";
  }
  std::cout << std::endl << std::endl;
}