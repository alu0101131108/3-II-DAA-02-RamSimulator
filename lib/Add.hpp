#ifndef ADD_
#define ADD_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Add : public Instruction
{
protected:
  int parameter_;

public:
  Add(RAM *ram, int line, int parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
  virtual void unassembly() = 0;
};

class AddInmediate : public Add
{
public:
  AddInmediate(RAM *ram, int line, int parameter)
      : Add(ram, line, parameter) {}
  void run();
  void unassembly();
};

class AddDirect : public Add
{
public:
  AddDirect(RAM *ram, int line, int parameter)
      : Add(ram, line, parameter) {}
  void run();
  void unassembly();
};

class AddIndirect : public Add
{
public:
  AddIndirect(RAM *ram, int line, int parameter)
      : Add(ram, line, parameter) {}
  void run();
  void unassembly();
};

#endif