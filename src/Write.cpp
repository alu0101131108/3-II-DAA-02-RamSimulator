#include "../lib/Write.hpp"

void WriteInmediate::run()
{
  ram_->writeToOutputBand(parameter_);
  ram_->incrementPc();
}

void WriteInmediate::unassembly()
{
  std::cout << "Instruction: WRITE" << std::endl;
  std::cout << "Addressing mode: Inmediate" << std::endl;
  std::cout << "Operand: " << parameter_ << std::endl << std::endl;
}

void WriteDirect::run()
{
  int value;
  ram_->readFromMemory(parameter_, value);
  ram_->writeToOutputBand(value);
  ram_->incrementPc();
}

void WriteDirect::unassembly()
{
  std::cout << "Instruction: WRITE" << std::endl;
  std::cout << "Addressing mode: Direct" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}

void WriteIndirect::run()
{
  int value, registerDir;
  ram_->readFromMemory(parameter_, registerDir);
  ram_->readFromMemory(registerDir, value);
  ram_->writeToOutputBand(value);
  ram_->incrementPc();
}

void WriteIndirect::unassembly()
{
  std::cout << "Instruction: WRITE" << std::endl;
  std::cout << "Addressing mode: Indirect" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}