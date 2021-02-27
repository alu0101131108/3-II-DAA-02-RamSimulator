#ifndef INSTRUCTION_
#define INSTRUCTION_
#include <iostream>
#include <vector>
#include <string>

class RAM;
class Instruction {
  protected:
    RAM* ram_;
    int line_;

  public:
    Instruction(RAM *ram, int line) : ram_(ram), line_(line) {}
    virtual void run() = 0;
};

#endif