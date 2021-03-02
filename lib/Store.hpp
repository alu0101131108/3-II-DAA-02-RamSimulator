#ifndef STORE_
#define STORE_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Store : public Instruction
{
protected:
  int parameter_;

public:
  Store(RAM *ram, int line, int parameter)
  : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
  virtual void unassembly() = 0;
};

class StoreDirect : public Store
{
public:
  StoreDirect(RAM *ram, int line, int parameter)
  : Store(ram, line, parameter) {}
  void run();
  void unassembly();
};

class StoreIndirect : public Store
{
public:
  StoreIndirect(RAM *ram, int line, int parameter)
  : Store(ram, line, parameter) {}
  void run();
  void unassembly();
};

#endif