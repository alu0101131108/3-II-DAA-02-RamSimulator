#include "../lib/Write.hpp"

void WriteInmediate::run()
{
  ram_->writeToOutputBand(parameter_);
  ram_->incrementPc();
}

void WriteDirect::run()
{
  int value;
  ram_->readFromMemory(parameter_, value);
  ram_->writeToOutputBand(value);
  ram_->incrementPc();
}

void WriteIndirect::run()
{
  int value, registerDir;
  ram_->readFromMemory(parameter_, registerDir);
  ram_->readFromMemory(registerDir, value);
  ram_->writeToOutputBand(value);
  ram_->incrementPc();
}