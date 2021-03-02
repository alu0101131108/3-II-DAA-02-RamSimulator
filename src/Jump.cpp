#include "../lib/Jump.hpp"

void Jump::run()
{
  int direction;
  ram_->getLabelDirection(parameter_, direction);
  ram_->setPc(direction);
}

void Jump::unassembly()
{
  std::cout << "Instruction: JUMP" << std::endl;
  std::cout << "Label: " << parameter_ << std::endl << std::endl;
}
