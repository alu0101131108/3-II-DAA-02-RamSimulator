#ifndef RAM_
#define RAM_
#include <string>
#include <vector>
#include <map>
#include <iostream>
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
    std::map<std::string, int> labelMap_;
    bool haltState_;
    int executedInstructionsCounter_;

  public:
    RAM(const int &inputBandSize = 0, const int &outputBandSize = 0, const int &memorySize = 16);
    void loadInstructionsFromFile(const std::string &filename);
    void loadInputBandFromFile(const std::string &filename);
    void saveOutputBandToFile(const std::string &filename);
    void readFromMemory(const int &registerIndex, int &value);
    void writeToMemory(const int &registerIndex, const int &value);
    void readFromInputBand(int &value);
    void writeToOutputBand(const int &value);
    void getLabelDirection(const std::string &label, int & direction);
    void setPc(const int &value);
    void incrementPc();
    void getHaltState(bool &halt);
    void setHaltState(const bool & haltState);
    void printMemory();
    void printInputBand();
    void printOutputBand();
    void runNextInstruction();
    void runFullProgram();
    void unassembly();
};



#endif