#ifndef JZERO_
#define JZERO_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Jzero : public Instruction
{
protected:
  std::string parameter_;

public:
  Jzero(RAM *ram, int line, std::string parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  void run();
};

#endif