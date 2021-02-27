#ifndef MEMORY_
#define MEMORY_
#include <vector>
#include <string>

class Memory {
  private:
    std::vector <int> registers_;

  public:
    Memory(const int &size = 50);
    void read(const int &registerIndex, int &value);
    void write(const int &registerIndex, const int &value);
    void toString(std::string &memoryAsString);

};

#endif