#include "../lib/Store.hpp"

void StoreDirect::run()
{
  std::cout << "Run() from StoreDirect called." << std::endl;
}

void StoreIndirect::run()
{
  std::cout << "Run() from StoreIndirect called." << std::endl;
}