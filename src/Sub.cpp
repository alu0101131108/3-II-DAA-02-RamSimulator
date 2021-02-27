#include "../lib/Sub.hpp"

void SubInmediate::run()
{
  std::cout << "Run() from SubInmediate called." << std::endl;
}

void SubDirect::run()
{
  std::cout << "Run() from SubDirect called." << std::endl;
}

void SubIndirect::run()
{
  std::cout << "Run() from SubIndirect called." << std::endl;
}