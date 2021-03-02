#ifndef MEMORY_
#define MEMORY_
#include <vector>
#include <string>
#include <iostream>

class Memory {
  private:
    std::vector <int> registers_;

  public:
    Memory(const int &size = 16);
    void read(const int &registerIndex, int &value);
    void write(const int &registerIndex, const int &value);
    void printRegisters();

};

#endif