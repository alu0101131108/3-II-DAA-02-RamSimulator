#include "../lib/Halt.hpp"

void Halt::run()
{
  ram_->setHaltState(true);
}

void Halt::unassembly()
{
  std::cout << "Instruction: HALT" << std::endl << std::endl;
}
