#ifndef RAM_
#define RAM_
#include <string>
#include <vector>
#include "Memory.hpp"
#include "Band.hpp"
#include "Load.hpp"
#include "Store.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Read.hpp"
#include "Write.hpp"
#include "Jump.hpp"
#include "Jgtz.hpp"
#include "Jzero.hpp"
#include "Halt.hpp"

class Instruction;
class RAM {
  private:
    Band inputBand_;
    Band outputBand_;
    Memory memory_;
    int pc_;
    std::vector<Instruction*> instructions_;

  public:
    RAM(const int &inputBandSize = 50, const int &outputBandSize = 50, const int &memorySize = 50);
    void loadInstructionsFromFile(const std::string &filename);
};



#endif