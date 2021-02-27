#ifndef JGTZ_
#define JGTZ_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Jgtz : public Instruction
{
protected:
  std::string parameter_;

public:
  Jgtz(RAM *ram, int line, std::string parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  void run();
};

#endif