#include "../lib/Load.hpp"

void LoadInmediate::run()
{
  std::cout << "Run() from LoadInmediate called." << std::endl;
}

void LoadDirect::run()
{
  std::cout << "Run() from LoadDirect called." << std::endl;
}

void LoadIndirect::run()
{
  std::cout << "Run() from LoadIndirect called." << std::endl;
}