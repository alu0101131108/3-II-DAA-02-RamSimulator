#include "../lib/Read.hpp"

void ReadDirect::run()
{
  int value;
  ram_->readFromInputBand(value);
  ram_->writeToMemory(parameter_, value);
  ram_->incrementPc();
}

void ReadDirect::unassembly()
{
  std::cout << "Instruction: READ" << std::endl;
  std::cout << "Addressing mode: Direct" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}

void ReadIndirect::run()
{
  int value, registerDir;
  ram_->readFromInputBand(value);
  ram_->readFromMemory(parameter_, registerDir);
  ram_->writeToMemory(registerDir, value);
  ram_->incrementPc();
}

void ReadIndirect::unassembly()
{
  std::cout << "Instruction: READ" << std::endl;
  std::cout << "Addressing mode: Indirect" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}