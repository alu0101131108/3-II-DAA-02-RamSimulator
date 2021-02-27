#ifndef SUB_
#define SUB_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Sub : public Instruction
{
protected:
  int parameter_;

public:
  Sub(RAM *ram, int line, int parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
};

class SubInmediate : public Sub
{
public:
  SubInmediate(RAM *ram, int line, int parameter)
      : Sub(ram, line, parameter) {}
  void run();
};

class SubDirect : public Sub
{
public:
  SubDirect(RAM *ram, int line, int parameter)
      : Sub(ram, line, parameter) {}
  void run();
};

class SubIndirect : public Sub
{
public:
  SubIndirect(RAM *ram, int line, int parameter)
      : Sub(ram, line, parameter) {}
  void run();
};

#endif