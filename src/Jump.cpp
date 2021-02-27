#include "../lib/Jump.hpp"

void Jump::run()
{
  int direction;
  ram_->getLabelDirection(parameter_, direction);
  ram_->setPc(direction);
}
