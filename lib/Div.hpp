#ifndef DIV_
#define DIV_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Div : public Instruction
{
protected:
  int parameter_;

public:
  Div(RAM *ram, int line, int parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
};

class DivInmediate : public Div
{
public:
  DivInmediate(RAM *ram, int line, int parameter)
      : Div(ram, line, parameter) {}
  void run();
};

class DivDirect : public Div
{
public:
  DivDirect(RAM *ram, int line, int parameter)
      : Div(ram, line, parameter) {}
  void run();
};

class DivIndirect : public Div
{
public:
  DivIndirect(RAM *ram, int line, int parameter)
      : Div(ram, line, parameter) {}
  void run();
};

#endif