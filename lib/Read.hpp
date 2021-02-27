#ifndef READ_
#define READ_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Read : public Instruction
{
protected:
  int parameter_;

public:
  Read(RAM *ram, int line, int parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
};

class ReadDirect : public Read
{
public:
  ReadDirect(RAM *ram, int line, int parameter)
      : Read(ram, line, parameter) {}
  void run();
};

class ReadIndirect : public Read
{
public:
  ReadIndirect(RAM *ram, int line, int parameter)
      : Read(ram, line, parameter) {}
  void run();
};

#endif