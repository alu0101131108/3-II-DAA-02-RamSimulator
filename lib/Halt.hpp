#ifndef HALT_
#define HALT_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Halt : public Instruction
{
public:
  Halt(RAM *ram, int line)
      : Instruction(ram, line) {}
  void run();
  void unassembly();
};

#endif