#include "../lib/Add.hpp"

void AddInmediate::run()
{
  std::cout << "Run() from AddInmediate called." << std::endl;
}

void AddDirect::run()
{
  std::cout << "Run() from AddDirect called." << std::endl;
}

void AddIndirect::run()
{
  std::cout << "Run() from AddIndirect called." << std::endl;
}