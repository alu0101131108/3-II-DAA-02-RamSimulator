#include "../lib/Add.hpp"

void AddInmediate::run()
{
  int accumulator;
  ram_->readFromMemory(0, accumulator);
  ram_->writeToMemory(0, accumulator + parameter_);
  ram_->incrementPc();
}

void AddInmediate::unassembly()
{
  std::cout << "Instruction: ADD" << std::endl;
  std::cout << "Addressing mode: Inmediate" << std::endl;
  std::cout << "Operand: " << parameter_ << std::endl << std::endl;
}

void AddDirect::run()
{
  int accumulator, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, value);
  ram_->writeToMemory(0, accumulator + value);
  ram_->incrementPc();
}

void AddDirect::unassembly()
{
  std::cout << "Instruction: ADD" << std::endl;
  std::cout << "Addressing mode: Direct" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}

void AddIndirect::run()
{
  int accumulator, valueRegister, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, valueRegister);
  ram_->readFromMemory(valueRegister, value);
  ram_->writeToMemory(0, accumulator + value);
  ram_->incrementPc();
}

void AddIndirect::unassembly()
{
  std::cout << "Instruction: ADD" << std::endl;
  std::cout << "Addressing mode: Indirect" << std::endl;
  std::cout << "Address: " << parameter_ << std::endl << std::endl;
}