#include "../lib/RAM.hpp"

RAM::RAM(const int &inputBandSize, const int &outputBandSize, const int &memorySize)
: inputBand_(inputBandSize), outputBand_(outputBandSize), memory_(memorySize),
pc_(0), haltState_(false), executedInstructionsCounter_(0) 
{}

void RAM::readFromMemory(const int &registerIndex, int &value)
{
  memory_.read(registerIndex, value);
}

void RAM::writeToMemory(const int &registerIndex, const int &value)
{
  memory_.write(registerIndex, value);
}

void RAM::readFromInputBand(int &value)
{
  inputBand_.read(value);
}

void RAM::writeToOutputBand(const int &value)
{
  outputBand_.write(value);
}

void RAM::getLabelDirection(const std::string &label, int &direction)
{
  if (labelMap_.find(label) != labelMap_.end())
  {
    direction = labelMap_[label];
  }
  else
  {
    std::cout << "ERROR: RAM::getLabelDirection, label not defined.";
    throw 30;
  } 
}

void RAM::setPc(const int &value)
{
  if (value + 1 > instructions_.size() || value < 0)
  {
    std::cout << "ERROR: Program Counter is out of valid range" << std::endl;
    throw 80;
  }
  pc_ = value;
}

void RAM::incrementPc()
{
  if (pc_ + 1 == instructions_.size())
  {
    std::cout << "ERROR: Program Counter is out of valid range, you might need a HALT instruction"<< std::endl;
    throw 80;
  }
    pc_++;
}

void RAM::getHaltState(bool &halt)
{
  halt = haltState_;
}

void RAM::setHaltState(const bool &haltState)
{
  haltState_ = haltState;
}

void RAM::printMemory() 
{
  memory_.printRegisters();
}

void RAM::printInputBand() 
{
  inputBand_.printCells();
}

void RAM::printOutputBand() 
{
  outputBand_.printCells();
}

void RAM::loadInputBandFromFile(const std::string &filename)
{
  inputBand_.loadFromFile(filename);
}

void RAM::saveOutputBandToFile(const std::string &filename)
{
  outputBand_.saveToFile(filename);
}

void RAM::loadInstructionsFromFile(const std::string &filename)
{
  std::ifstream ifs;
  std::string line, inputInstruction, inputAddressing, inputLabel, inputRemainer;
  std::vector<std::string> cleanInputLines;
  std::vector<std::string> labels;
  int addressingMode, inputNumber;
  bool isDigit;
  char currentSymbol;
  ifs.open(filename);
  if(ifs.fail())
  {
    std::cout << "ERROR: Can not open file: " + filename << std::endl;
    throw 10;
  }

  // Get input file as vector of lines.
  while (!ifs.eof())
  {
    getline(ifs, line);
    for (int i = 0; i < line.size(); i++)
    {
      currentSymbol = line[i];
      if (currentSymbol >= 'A' && currentSymbol <= 'Z') // Get everything as lower case.
      {
        line[i] = tolower(currentSymbol);
      }
      else if (currentSymbol == ';' || currentSymbol == '#')
      {
        line.resize(i);
        break;
      }
      else if (currentSymbol == ' ' || currentSymbol == '\n')
      {
        line[i] = ' ';
      }
    }
    if (line.size() > 1) // Meaningfull line.
    {
      cleanInputLines.push_back(line);
    }
  }
  ifs.close();
  
  // Analize line by line.
  for (int i = 0; i < cleanInputLines.size(); i++)
  {
    line = cleanInputLines[i];
    std::stringstream stringStream(line);
    stringStream >> inputInstruction;

    // Check labeling.
    if (inputInstruction[inputInstruction.size() - 1] == ':')
    {
      inputInstruction.resize(inputInstruction.size() - 1);
      inputLabel = inputInstruction;
      labelMap_[inputLabel] = i;
      stringStream >> inputInstruction;
    }
    
    // Check if instruction parameter is valid.
    if (inputInstruction != "jump" && inputInstruction != "jgtz" && inputInstruction != "jzero" && inputInstruction != "halt")
    {
      // Check addressing mode.
      addressingMode = -1;
      stringStream >> inputAddressing;
      if (inputAddressing[0] == '=') // Inmediate.
      {
        addressingMode = 0;
        inputAddressing.erase(0, 1);
      }
      else if (inputAddressing[0] == '*') // Indirect.
      {
        addressingMode = 1;
        inputAddressing.erase(0, 1);
      }
      else if (inputAddressing[0] >= '0' && inputAddressing[0] <= '9')  // Direct, can not be negative.
      {
        addressingMode = 2;
      }
      else
      {
        std::cout << "ERROR: Bad syntax at addressing mode" << std::endl;
        std::cout << "Caused by: [" + inputAddressing + "] at line " << i << std::endl << std::endl;
        throw 20;
      }
      // Check if the remaining value of inputAddressing is an integer.
      for (int j = 0; j < inputAddressing.size(); j++)
      {
        isDigit = (inputAddressing[j] >= '0' && inputAddressing[j] <= '9') ? true : false;
        if ((j == 0 && inputAddressing[j] != '-' && !(isDigit)) || (j != 0 && !(isDigit)))
        {
          std::cout << "ERROR: Non integer value given as instruction parameter" << std::endl;
          std::cout << "Caused by: [" + inputAddressing + "] at line " << i << std::endl << std::endl;
          throw 21;
        }
      }
      inputNumber = stoi(inputAddressing);
    }
    else if (inputInstruction != "halt")
    {
      stringStream >> inputLabel;
      labels.push_back(inputLabel);
    }

    // Check there is no more string content to stream from line.
    while (!stringStream.eof())
    {
      stringStream >> inputRemainer;
      if (inputRemainer.size() > 0 && (int) inputRemainer[0] < 32)
      {
        std::cout << "ERROR: Too many arguments at instruction in ram program file" << std::endl;
        std::cout << "Caused by: [" + inputRemainer + "] at line " << i << std::endl << std::endl;
        throw 22;
      }
    }
  
    // Check if instruction is valid, if it is, its added to instructions_ attribute.
    if (inputInstruction == "load")
    {
      if (addressingMode == 0)
      {
        instructions_.push_back(new LoadInmediate(this, i, inputNumber));
      }
      else if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new LoadIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new LoadDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Negative address for memory register" << std::endl;
        std::cout << "Caused by: [" << inputNumber << "] at line " << i << std::endl << std::endl;
        throw 23;
      }
    }
    else if (inputInstruction == "store")
    {
      if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new StoreIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new StoreDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Illegal address or adressing mode." << std::endl;
        std::cout << "Caused by: [" + cleanInputLines[i] + "] at line " << i << std::endl << std::endl;
        throw 20;
      }
    }
    else if (inputInstruction == "add")
    {
      if (addressingMode == 0)
      {
        instructions_.push_back(new AddInmediate(this, i, inputNumber));
      }
      else if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new AddIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new AddDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Negative address for memory register" << std::endl;
        std::cout << "Caused by: [" << inputNumber << "] at line " << i << std::endl << std::endl;
        throw 23;
      }
    }
    else if (inputInstruction == "sub")
    {
      if (addressingMode == 0)
      {
        instructions_.push_back(new SubInmediate(this, i, inputNumber));
      }
      else if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new SubIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new SubDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Negative address for memory register" << std::endl;
        std::cout << "Caused by: [" << inputNumber << "] at line " << i << std::endl << std::endl;
        throw 23;
      }
    }
    else if (inputInstruction == "mult")
    {
      if (addressingMode == 0)
      {
        instructions_.push_back(new MultInmediate(this, i, inputNumber));
      }
      else if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new MultIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new MultDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Negative address for memory register" << std::endl;
        std::cout << "Caused by: [" << inputNumber << "] at line " << i << std::endl << std::endl;
        throw 23;
      }
    }
    else if (inputInstruction == "div")
    {
      if (addressingMode == 0)
      {
        instructions_.push_back(new DivInmediate(this, i, inputNumber));
      }
      else if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new DivIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new DivDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Negative address for memory register" << std::endl;
        std::cout << "Caused by: [" << inputNumber << "] at line " << i << std::endl << std::endl;
        throw 23;
      }
    }
    else if (inputInstruction == "read")
    {
      if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new ReadIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new ReadDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Illegal address or adressing mode." << std::endl;
        std::cout << "Caused by: [" + cleanInputLines[i] + "] at line " << i << std::endl << std::endl;
        throw 20;
      }
    }
    else if (inputInstruction == "write")
    {
      if (addressingMode == 0)
      {
        instructions_.push_back(new WriteInmediate(this, i, inputNumber));
      }
      else if (addressingMode == 1 && inputNumber >= 0)
      {
        instructions_.push_back(new WriteIndirect(this, i, inputNumber));
      }
      else if (addressingMode == 2 && inputNumber >= 0)
      {
        instructions_.push_back(new WriteDirect(this, i, inputNumber));
      }
      else
      {
        std::cout << "ERROR: Negative address for memory register" << std::endl;
        std::cout << "Caused by: [" << inputNumber << "] at line " << i << std::endl << std::endl;
        throw 23;
      }
    }
    else if (inputInstruction == "jump")
    {
      instructions_.push_back(new Jump(this, i, inputLabel));
    }
    else if (inputInstruction == "jgtz")
    {
      instructions_.push_back(new Jgtz(this, i, inputLabel));
    }
    else if (inputInstruction == "jzero")
    {
      instructions_.push_back(new Jzero(this, i, inputLabel));
    }
    else if (inputInstruction == "halt")
    {
      instructions_.push_back(new Halt(this, i));
    }
    else  // No matching instruction.
    {
      std::cout << "ERROR: Unknown instruction in ram program file" << std::endl;
      std::cout << "Caused by: [" + inputInstruction + "] at line " << i << std::endl << std::endl;
      throw 21;
    }
  }
}

void RAM::runNextInstruction() 
{
  if (!haltState_)
  {
    instructions_[pc_]->run();
    executedInstructionsCounter_++;
  }
  else
  {
    std::cout << "RAM reached Halt state" << std::endl;
  }
}

void RAM::runFullProgram() 
{
  if (!haltState_)
  {
    while (!haltState_)
    {
      instructions_[pc_]->run();
      executedInstructionsCounter_++;
    }
    std::cout << "Executed instructions: " << executedInstructionsCounter_ << std::endl;
  }
  else 
  {
    std::cout << "RAM reached Halt state" << std::endl;   
  }
  
}

void RAM::unassembly()
{
  instructions_[pc_]->unassembly();
}