#include "../lib/Load.hpp"

void LoadInmediate::run()
{
  ram_->writeToMemory(0, parameter_);
  ram_->incrementPc();
}

void LoadDirect::run()
{
  int value;
  ram_->readFromMemory(parameter_, value);
  ram_->writeToMemory(0, value);
  ram_->incrementPc();
}

void LoadIndirect::run()
{
  int value, valueRegister;
  ram_->readFromMemory(parameter_, valueRegister);
  ram_->readFromMemory(valueRegister, value);
  ram_->writeToMemory(0, value);
  ram_->incrementPc();
}