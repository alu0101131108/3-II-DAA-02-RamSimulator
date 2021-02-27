#ifndef WRITE_
#define WRITE_
#include <iostream>
#include <vector>
#include <string>
#include "Instruction.hpp"
#include "RAM.hpp"

class Write : public Instruction
{
protected:
  int parameter_;

public:
  Write(RAM *ram, int line, int parameter)
      : Instruction(ram, line), parameter_(parameter) {}
  virtual void run() = 0;
};

class WriteInmediate : public Write
{
public:
  WriteInmediate(RAM *ram, int line, int parameter)
      : Write(ram, line, parameter) {}
  void run();
};

class WriteDirect : public Write
{
public:
  WriteDirect(RAM *ram, int line, int parameter)
      : Write(ram, line, parameter) {}
  void run();
};

class WriteIndirect : public Write
{
public:
  WriteIndirect(RAM *ram, int line, int parameter)
      : Write(ram, line, parameter) {}
  void run();
};

#endif