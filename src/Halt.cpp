#include "../lib/Halt.hpp"

void Halt::run()
{
  ram_->setHaltState(true);
}
