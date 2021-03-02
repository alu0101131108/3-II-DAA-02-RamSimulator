#include "../lib/Sub.hpp"

void SubInmediate::run()
{
  int accumulator;
  ram_->readFromMemory(0, accumulator);
  ram_->writeToMemory(0, accumulator - parameter_);
  ram_->incrementPc();
}

void SubInmediate::unassembly()
{
  std::cout << "Instruction: SUB" << std::endl;
  std::cout << "Addressing mode: Inmediate" << std::endl;
  std::cout << "Operand: " << parameter_ << std::endl << std::endl;
}

void SubDirect::run()
{
  int accumulator, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, value);
  ram_->writeToMemory(0, accumulator - value);
  ram_->incrementPc();
}

void SubDirect::unassembly()
{
  std::cout << "Instruction: SUB" << std::endl;
  std::cout << "Addressing mode: Direct" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}

void SubIndirect::run()
{
  int accumulator, valueRegister, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, valueRegister);
  ram_->readFromMemory(valueRegister, value);
  ram_->writeToMemory(0, accumulator - value);
  ram_->incrementPc();
}

void SubIndirect::unassembly()
{
  std::cout << "Instruction: SUB" << std::endl;
  std::cout << "Addressing mode: Indirect" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}