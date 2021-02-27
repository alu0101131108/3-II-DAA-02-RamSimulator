#ifndef LOAD_
#define LOAD_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Load : public Instruction
{
protected:
  int parameter_;

public:
  Load(RAM *ram, int line, int parameter)
  : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
};

class LoadInmediate : public Load
{
public:
  LoadInmediate(RAM *ram, int line, int parameter) 
  : Load(ram, line, parameter) {}
  void run();
};

class LoadDirect : public Load
{
public:
  LoadDirect(RAM *ram, int line, int parameter)
  : Load(ram, line, parameter) {}
  void run();
};

class LoadIndirect : public Load
{
public:
  LoadIndirect(RAM *ram, int line, int parameter)
  : Load(ram, line, parameter) {}
  void run();
};

#endif