#include "../lib/Add.hpp"

void AddInmediate::run()
{
  int accumulator;
  ram_->readFromMemory(0, accumulator);
  ram_->writeToMemory(0, accumulator + parameter_);
  ram_->incrementPc();
}

void AddDirect::run()
{
  int accumulator, value;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, value);
  ram_->writeToMemory(0, accumulator + value);
  ram_->incrementPc();
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