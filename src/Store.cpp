#include "../lib/Store.hpp"

void StoreDirect::run()
{
  int accumulator;
  ram_->readFromMemory(0, accumulator);
  ram_->writeToMemory(parameter_, accumulator);
  ram_->incrementPc();
}

void StoreIndirect::run()
{
  int accumulator, registerDir;
  ram_->readFromMemory(0, accumulator);
  ram_->readFromMemory(parameter_, registerDir);
  ram_->writeToMemory(registerDir, accumulator);
  ram_->incrementPc();
}