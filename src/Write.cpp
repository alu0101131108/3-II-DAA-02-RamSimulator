#include "../lib/Write.hpp"

void WriteInmediate::run()
{
  std::cout << "Run() from WriteInmediate called." << std::endl;
}

void WriteDirect::run()
{
  std::cout << "Run() from WriteDirect called." << std::endl;
}

void WriteIndirect::run()
{
  std::cout << "Run() from WriteIndirect called." << std::endl;
}