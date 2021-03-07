#include "../lib/Band.hpp"

Band::Band(const int &size) : cells_(size, 0), headPointer_(0)
{}

void Band::read(int &value)
{
  if (headPointer_ < cells_.size())
  {
    value = cells_[headPointer_];
    headPointer_++;
  }
  else 
  {
    std::cout << "ERROR: Band::read() failed. No input given." << std::endl;
    throw 5;
  }
  
}

void Band::write(const int &value)
{
  cells_.push_back(value);
  headPointer_++;
}

void Band::printCells() 
{
  for (int i = 0; i < cells_.size(); i++)
  {
    if (i == headPointer_)
    {
      std::cout << "|[" << cells_[i] << "]| ";
    }
    else
    {
      std::cout << "|" << cells_[i] << "| "; 
    }
  }
    std::cout << std::endl;
}

void Band::loadFromFile(const std::string &filename)
{
  std::ifstream ifs;
  std::string line, cleanInput = "";
  char currentSymbol;
  int tempValue;
  ifs.open(filename);
  if (ifs.fail())
  {
    std::cout << "ERROR: Can not open file: " + filename << std::endl;
    throw 10;
  }
  while (!ifs.eof())
  {
    getline(ifs, line);
    for (int i = 0; i < line.size(); i++)
    {
      currentSymbol = line[i];
      if (currentSymbol == ';' || currentSymbol == '#')
      {
        line.resize(i);
        break;
      }
    }
    cleanInput = cleanInput + " " + line;
  }
  std::istringstream ss(cleanInput);
  while (!ss.eof())
  {
    if (!(ss >> tempValue))
    {
      std::cout << "ERROR: Bad syntax at input band" << std::endl << std::endl;
      throw 40;
    }
    cells_.push_back(tempValue);
  }
  ifs.close();
}

void Band::saveToFile(const std::string &filename)
{
  std::ofstream ofs;
  ofs.open(filename);
  if (ofs.fail())
  {
    std::cout << "ERROR: Can not open file: " + filename << std::endl;
    throw 10;
  }
  for (int i = 0; i < cells_.size(); i++) 
  {
    ofs << cells_[i] << std::endl;
  }
  ofs.close();
}
