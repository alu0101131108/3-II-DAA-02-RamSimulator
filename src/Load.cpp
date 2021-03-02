#include "../lib/Load.hpp"

void LoadInmediate::run()
{
  ram_->writeToMemory(0, parameter_);
  ram_->incrementPc();
}

void LoadInmediate::unassembly()
{
  std::cout << "Instruction: LOAD" << std::endl;
  std::cout << "Addressing mode: Inmediate" << std::endl;
  std::cout << "Operand: " << parameter_ << std::endl << std::endl;
}

void LoadDirect::run()
{
  int value;
  ram_->readFromMemory(parameter_, value);
  ram_->writeToMemory(0, value);
  ram_->incrementPc();
}

void LoadDirect::unassembly()
{
  std::cout << "Instruction: LOAD" << std::endl;
  std::cout << "Addressing mode: Direct" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}

void LoadIndirect::run()
{
  int value, valueRegister;
  ram_->readFromMemory(parameter_, valueRegister);
  ram_->readFromMemory(valueRegister, value);
  ram_->writeToMemory(0, value);
  ram_->incrementPc();
}

void LoadIndirect::unassembly()
{
  std::cout << "Instruction: LOAD" << std::endl;
  std::cout << "Addressing mode: Indirect" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}