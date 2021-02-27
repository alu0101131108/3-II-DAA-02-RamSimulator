#ifndef JUMP_
#define JUMP_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Jump : public Instruction
{
protected:
  std::string parameter_;

public:
  Jump(RAM *ram, int line, std::string parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  void run();
};


#endif