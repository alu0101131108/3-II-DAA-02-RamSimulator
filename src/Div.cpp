#include "../lib/Div.hpp"

void DivInmediate::run()
{
  int accumulator;
  ram_->readFromMemory(0, accumulator);
  ram_->writeToMemory(0, accumulator / parameter_);
  ram_->incrementPc();
}

void DivInmediate::unassembly()
{
  std::cout << "Instruction: DIV" << std::endl;
  std::cout << "Addressing mode: Inmediate" << std::endl;
  std::cout << "Operand: " << parameter_ << std::endl << std::endl;
}

void DivDirect::run()
{
  int accumulator, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, value);
  ram_->writeToMemory(0, accumulator / value);
  ram_->incrementPc();
}

void DivDirect::unassembly()
{
  std::cout << "Instruction: DIV" << std::endl;
  std::cout << "Addressing mode: Direct" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}

void DivIndirect::run()
{
  int accumulator, valueRegister, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, valueRegister);
  ram_->readFromMemory(valueRegister, value);
  ram_->writeToMemory(0, accumulator / value);
  ram_->incrementPc();
}

void DivIndirect::unassembly()
{
  std::cout << "Instruction: DIV" << std::endl;
  std::cout << "Addressing mode: Indirect" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}