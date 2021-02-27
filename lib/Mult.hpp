#ifndef MULT_
#define MULT_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Mult : public Instruction
{
protected:
  int parameter_;

public:
  Mult(RAM *ram, int line, int parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
};

class MultInmediate : public Mult
{
public:
  MultInmediate(RAM *ram, int line, int parameter)
      : Mult(ram, line, parameter) {}
  void run();
};

class MultDirect : public Mult
{
public:
  MultDirect(RAM *ram, int line, int parameter)
      : Mult(ram, line, parameter) {}
  void run();
};

class MultIndirect : public Mult
{
public:
  MultIndirect(RAM *ram, int line, int parameter)
      : Mult(ram, line, parameter) {}
  void run();
};

#endif