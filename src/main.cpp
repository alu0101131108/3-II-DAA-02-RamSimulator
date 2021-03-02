#include "../lib/RAM.hpp"

int main(int argc, char **argv)
{
  if (argc == 5)
  {
      std::string ramProgramFilename(argv[1]);
      std::string inputBandFilename(argv[2]);
      std::string outputBandFilename(argv[3]);
      std::string debug(argv[4]);
      RAM ram;
    try
    {
      ram.loadInstructionsFromFile("../ioFiles/ram-programs/" + ramProgramFilename);
      ram.loadInputBandFromFile("../ioFiles/" + inputBandFilename);

      if (debug == "0")
      {
        ram.runFullProgram();
        ram.saveOutputBandToFile("../ioFiles/" + outputBandFilename);
      }
      else if (debug == "1")
      {
        std::cout << "Debug mode active." << std::endl;
        char option;
        bool exit = false;
        while(!exit)
        {
          std::cout << "Enter option, h for help:\n";
          std::cin >> option;
          switch (option)
          {
          case 'r':
            ram.printMemory();
            break;
          case 't':
            ram.runNextInstruction();
            break;
          case 'e':
            ram.runFullProgram();
            break;
          case 's':
            ram.unassembly();
            break;
          case 'i':
            ram.printInputBand();
            break;
          case 'o':
            ram.printOutputBand();
            break;
          case 'h':
            std::cout << "r: ver los registros" << std::endl;
            std::cout << "t: traza" << std::endl;
            std::cout << "e: ejecutar" << std::endl;
            std::cout << "s: desensamblador" << std::endl;
            std::cout << "i: ver cinta de entrada" << std::endl;
            std::cout << "o: ver cinta de salida" << std::endl;
            std::cout << "h: ayuda" << std::endl;
            std::cout << "x: salir" << std::endl;

            break;
          case 'x':
            exit = true;
            break;

          default:
            std::cout << "Invalid option\n";
            break;
          }
        }
        ram.saveOutputBandToFile("../ioFiles/" + outputBandFilename);
      }
      else
      {
        std::cout << "ERROR: Invalid value for debug parameter\n";
        std::cout << "Usage: Use \"0\" or \"1\"\n";
      }
    }
    catch(int e)
    {
      ram.saveOutputBandToFile("../ioFiles/" + outputBandFilename);
      std::cout << "Error encountered - process will be ended." << std::endl;
    }
  }
  else
  {
    std::cout << "ERROR: 4 arguments expected\n";
    std::cout << "./ram_sim ram_program.ram input_tape.in output_tape.out debug";
  }
  
  return 0;
}