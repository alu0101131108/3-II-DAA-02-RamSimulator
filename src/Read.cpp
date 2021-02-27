#include "../lib/Read.hpp"

void ReadDirect::run()
{
  int value;
  ram_->readFromInputBand(value);
  ram_->writeToMemory(parameter_, value);
  ram_->incrementPc();
}

void ReadIndirect::run()
{
  int value, registerDir;
  ram_->readFromInputBand(value);
  ram_->readFromMemory(parameter_, registerDir);
  ram_->writeToMemory(registerDir, value);
  ram_->incrementPc();
}