#ifndef BAND_
#define BAND_
#include <vector>
#include <string>

class Band {
  private:
    std::vector<int> cells_;
    int headPointer_;

  public:
    Band(const int &size = 50);
    void read(int &value);
    void write(const int &value);
    void loadFromFile(const std::string &filename);
    void saveToFile(const std::string &filename);
};

#endif