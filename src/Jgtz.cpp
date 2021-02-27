#include "../lib/Jgtz.hpp"

void Jgtz::run()
{
  int accumulator;
  ram_->readFromMemory(0, accumulator);
  if (accumulator > 0)
  {
    int direction;
    ram_->getLabelDirection(parameter_, direction);
    ram_->setPc(direction);
  }
  else
  {
    ram_->incrementPc();
  }
}
